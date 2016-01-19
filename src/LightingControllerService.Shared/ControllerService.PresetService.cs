using System;
using org.allseen.LSF.ControllerService;
using Windows.Devices.AllJoyn;
using Windows.Foundation;
using System.Threading.Tasks;
using org.allseen.LSF.ControllerService.Preset;
using System.Collections.Generic;
using System.Text;
using System.Collections.ObjectModel;

namespace LightingControllerService
{
    internal partial class ControllerService : IPresetService
    {
        public Dictionary<string, object> DefaultLampState { get; set; } = new Dictionary<string, object>()
        {
            //TODO: Load from disk
          { "OnOff", true },
          { "Saturation", (UInt32)0 },
          { "Brightness", UInt32.MaxValue },
          { "Hue", 0 },
          { "ColorTemp", 2800 }
        };
        private Dictionary<string, Preset> Presets = new Dictionary<string, Preset>();

        private void SavePresets()
        {
            var container = Windows.Storage.ApplicationData.Current.LocalSettings.CreateContainer("Presets", Windows.Storage.ApplicationDataCreateDisposition.Always);
            container.Values.Clear();
            foreach (var preset in Presets)
            {
                container.Values[preset.Key] = preset.Value.Serialize();
            }
        }

        private void SaveDefaultLampState()
        {
            var container = Windows.Storage.ApplicationData.Current.LocalSettings.CreateContainer("Presets", Windows.Storage.ApplicationDataCreateDisposition.Always);
            container.Values["DEFAULT_LAMP_STATE"] = new Preset("Default", "en", DefaultLampState).Serialize();
        }

        private void LoadPresets()
        {
            var container = Windows.Storage.ApplicationData.Current.LocalSettings.CreateContainer("Presets", Windows.Storage.ApplicationDataCreateDisposition.Always);
            foreach (var preset in container.Values)
            {
                Presets[preset.Key] = Preset.FromString((string)preset.Value);
            }
        }

        private void LoadDefaultLampState()
        {
            var container = Windows.Storage.ApplicationData.Current.LocalSettings.CreateContainer("Presets", Windows.Storage.ApplicationDataCreateDisposition.Always);
            if (container.Values.ContainsKey("DEFAULT_LAMP_STATE"))
            {
                DefaultLampState = Preset.FromString((string)container.Values["DEFAULT_STATE"]).State;
            }
        }

        public class Preset
        {
            public Preset(string name, string language, IReadOnlyDictionary<string, object> properties)
                : this(new KeyValuePair<string,string>[] { new KeyValuePair<string, string>(language, name) }, properties)
            {
            }
            public Preset(IEnumerable<KeyValuePair<string, string>> names, IReadOnlyDictionary<string,object> properties)
            {
                foreach (var lang in names)
                    PresetName[lang.Key] = lang.Value;
                foreach (var prop in properties)
                    State[prop.Key] = prop.Value;
            }

            public Dictionary<string, string> PresetName { get; } = new Dictionary<string, string>();
            public Dictionary<string, object> State { get; set; } = new Dictionary<string, object>();

            public string Serialize()
            {
                //TODO: Use JSON serialization
                StringBuilder sb = new StringBuilder();
                foreach (var l in PresetName)
                    sb.Append($"{l.Key}={l.Value}\t");
                foreach (var l in State)
                    sb.AppendLine($"{l.Key}\t{l.Value.GetType().FullName}\t{l.Value}");
                return sb.ToString();
            }
            public static Preset FromString(string str)
            {
                //TODO: Use JSON serialization
                string[] lines = str.Split(new char[] { '\n' });
                var languages = lines[0].Split(new char[] { '\t' }, StringSplitOptions.RemoveEmptyEntries);
                Dictionary<string, string> names = new Dictionary<string, string>();
                foreach (var item in languages)
                {
                    var lang = item.Split(new char[] { '=' });
                    names[lang[0]] = lang[1];
                }
                Dictionary<string, object> properties = new Dictionary<string, object>();
                for (int i = 1; i < lines.Length; i++)
                {
                    var vals = lines[i].Split(new char[] { '\t' });
                    var type = Type.GetType(vals[1]);
                    var val = Convert.ChangeType(vals[2], type, System.Globalization.CultureInfo.InvariantCulture);
                    properties[vals[0]] = val;
                }
                return new Preset(names, properties);
            }

        }
        IAsyncOperation<PresetCreatePresetResult> IPresetService.CreatePresetAsync(AllJoynMessageInfo info, IReadOnlyDictionary<string, object> LampState, string PresetName, string Language)
        {
            if (string.IsNullOrEmpty(PresetName))
                return Task.FromResult(PresetCreatePresetResult.CreateFailureResult(12)).AsAsyncOperation(); //Name was empty

            if (string.IsNullOrWhiteSpace(Language))
                return Task.FromResult(PresetCreatePresetResult.CreateFailureResult(11)).AsAsyncOperation(); //Invalid arguments

            string presetId = Guid.NewGuid().ToString();

            Preset group = new Preset(PresetName, Language, LampState);
            Presets.Add(presetId, group);
            SavePresets();
            PresetProducer.Signals.PresetsCreated(new List<string>() { presetId }.AsReadOnly());

            return Task.FromResult(PresetCreatePresetResult.CreateSuccessResult(0, presetId)).AsAsyncOperation();

        }

        IAsyncOperation<PresetDeletePresetResult> IPresetService.DeletePresetAsync(AllJoynMessageInfo info, string PresetID)
        {
            if (!Presets.ContainsKey(PresetID))
                return Task.FromResult(PresetDeletePresetResult.CreateFailureResult(16)).AsAsyncOperation();
            LampGroups.Remove(PresetID);
            SavePresets();
            PresetProducer.Signals.PresetsDeleted(new List<string> { PresetID });
            return Task.FromResult(PresetDeletePresetResult.CreateSuccessResult(0, PresetID)).AsAsyncOperation();
        }

        IAsyncOperation<PresetGetAllPresetIDsResult> IPresetService.GetAllPresetIDsAsync(AllJoynMessageInfo info)
        {
            return Task.FromResult(PresetGetAllPresetIDsResult.CreateSuccessResult(0, new List<string>(Presets.Keys))).AsAsyncOperation();
        }

        IAsyncOperation<PresetGetDefaultLampStateResult> IPresetService.GetDefaultLampStateAsync(AllJoynMessageInfo info)
        {
            return Task.FromResult(PresetGetDefaultLampStateResult.CreateSuccessResult(0, DefaultLampState)).AsAsyncOperation();
        }

        IAsyncOperation<PresetGetPresetResult> IPresetService.GetPresetAsync(AllJoynMessageInfo info, string PresetID)
        {
            if (!LampGroups.ContainsKey(PresetID))
                return Task.FromResult(PresetGetPresetResult.CreateFailureResult(16)).AsAsyncOperation();
            var preset = Presets[PresetID];
            return Task.FromResult(PresetGetPresetResult.CreateSuccessResult(0, PresetID, preset.State)).AsAsyncOperation();
        }

        IAsyncOperation<PresetGetPresetNameResult> IPresetService.GetPresetNameAsync(AllJoynMessageInfo info, string PresetID, string Language)
        {
            if (!Presets.ContainsKey(PresetID))
                return Task.FromResult(PresetGetPresetNameResult.CreateFailureResult(16)).AsAsyncOperation();
            var preset = Presets[PresetID];

            if (preset.PresetName.ContainsKey(Language))
                return Task.FromResult(PresetGetPresetNameResult.CreateSuccessResult(0, PresetID, Language, preset.PresetName[Language])).AsAsyncOperation();
            return Task.FromResult(PresetGetPresetNameResult.CreateFailureResult(16)).AsAsyncOperation();
        }

        IAsyncOperation<PresetGetVersionResult> IPresetService.GetVersionAsync(AllJoynMessageInfo info)
        {
            return Task.FromResult(PresetGetVersionResult.CreateSuccessResult(InterfaceVersion)).AsAsyncOperation();
        }

        IAsyncOperation<PresetSetDefaultLampStateResult> IPresetService.SetDefaultLampStateAsync(AllJoynMessageInfo info, IReadOnlyDictionary<string, object> LampState)
        {
            var props = new Dictionary<string, object>();
            foreach (var prop in LampState)
                props[prop.Key] = prop.Value;
            DefaultLampState = props;
            SaveDefaultLampState();
            return Task.FromResult(PresetSetDefaultLampStateResult.CreateSuccessResult(0)).AsAsyncOperation();
        }

        IAsyncOperation<PresetSetPresetNameResult> IPresetService.SetPresetNameAsync(AllJoynMessageInfo info, string PresetID, string PresetName, string Language)
        {
            if (!Presets.ContainsKey(PresetID))
                return Task.FromResult(PresetSetPresetNameResult.CreateFailureResult(16)).AsAsyncOperation();
            if (string.IsNullOrEmpty(PresetName))
                return Task.FromResult(PresetSetPresetNameResult.CreateFailureResult(12)).AsAsyncOperation();
            if (string.IsNullOrEmpty(Language))
                return Task.FromResult(PresetSetPresetNameResult.CreateFailureResult(5)).AsAsyncOperation();
            var group = Presets[PresetID];
            group.PresetName[Language] = PresetName;
            SavePresets();
            PresetProducer.Signals.PresetsNameChanged(new List<string>() { PresetID }.AsReadOnly());
            return Task.FromResult(PresetSetPresetNameResult.CreateSuccessResult(0, PresetID, Language)).AsAsyncOperation();
        }

        IAsyncOperation<PresetUpdatePresetResult> IPresetService.UpdatePresetAsync(AllJoynMessageInfo info, string PresetID, IReadOnlyDictionary<string, object> LampState)
        {
            if (!Presets.ContainsKey(PresetID))
                return Task.FromResult(PresetUpdatePresetResult.CreateFailureResult(16)).AsAsyncOperation();
            var preset = Presets[PresetID];
            var props = new Dictionary<string, object>();
            foreach (var prop in LampState)
                props[prop.Key] = prop.Value;
            preset.State = props;
            SavePresets();
            PresetProducer.Signals.PresetsUpdated(new List<string> { PresetID });

            return Task.FromResult(PresetUpdatePresetResult.CreateSuccessResult(0, PresetID)).AsAsyncOperation();
        }
    }
}