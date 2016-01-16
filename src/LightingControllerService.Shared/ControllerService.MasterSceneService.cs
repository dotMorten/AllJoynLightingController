using System;
using System.Linq;
using org.allseen.LSF.ControllerService;
using Windows.Devices.AllJoyn;
using Windows.Foundation;
using System.Threading.Tasks;
using org.allseen.LSF.ControllerService.MasterScene;
using System.Collections.Generic;
using System.Text;

namespace LightingControllerService
{
    internal partial class ControllerService : IMasterSceneService
    {
        private Dictionary<string, MasterScene> MasterScenes = new Dictionary<string, MasterScene>();

        private void SaveMasterScenes()
        {
            var container = Windows.Storage.ApplicationData.Current.LocalSettings.CreateContainer("MasterScenes", Windows.Storage.ApplicationDataCreateDisposition.Always);
            container.Values.Clear();
            foreach (var preset in MasterScenes)
            {
                container.Values[preset.Key] = preset.Value.Serialize();
            }
        }

        private void LoadMasterScenes()
        {
            var container = Windows.Storage.ApplicationData.Current.LocalSettings.CreateContainer("MasterScenes", Windows.Storage.ApplicationDataCreateDisposition.Always);
            foreach (var preset in container.Values)
            {
                MasterScenes[preset.Key] = MasterScene.FromString((string)preset.Value);
            }
        }

        public class MasterScene
        {
            public MasterScene(string name, string language, IEnumerable<string> scenes)
                : this(new KeyValuePair<string, string>[] { new KeyValuePair<string, string>(language, name) }, scenes)
            {
            }
            public MasterScene(IEnumerable<KeyValuePair<string, string>> names, IEnumerable<string> scenes)
            {
                foreach (var lang in names)
                    MasterSceneName[lang.Key] = lang.Value;
                Scenes = scenes.ToList();
            }

            public Dictionary<string, string> MasterSceneName { get; } = new Dictionary<string, string>();
            public IList<string> Scenes { get; set; } = new List<string>();

            public string Serialize()
            {
                //TODO: Use JSON serialization
                StringBuilder sb = new StringBuilder();
                foreach (var l in MasterSceneName)
                    sb.Append($"{l.Key}={l.Value}\t");
                foreach (var l in Scenes)
                    sb.AppendLine(l);
                return sb.ToString();
            }
            public static MasterScene FromString(string str)
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
                List<string> sceneId = new List<string>();
                for (int i = 1; i < lines.Length; i++)
                {
                    sceneId.Add(lines[i]);
                }
                return new MasterScene(names, sceneId);
            }

        }

        IAsyncOperation<MasterSceneApplyMasterSceneResult> IMasterSceneService.ApplyMasterSceneAsync(AllJoynMessageInfo info, string MasterSceneID)
        {
            if (!MasterScenes.ContainsKey(MasterSceneID))
                return Task.FromResult(MasterSceneApplyMasterSceneResult.CreateFailureResult(16)).AsAsyncOperation();

            var masterScene = MasterScenes[MasterSceneID];

            var producer = (org.allseen.LSF.ControllerService.Scene.ISceneService)this;
            foreach (var scene in masterScene.Scenes)
            {
                var _ = producer.ApplySceneAsync(info, scene);
            }
            return Task.FromResult(MasterSceneApplyMasterSceneResult.CreateSuccessResult(0, MasterSceneID)).AsAsyncOperation();
        }

        IAsyncOperation<MasterSceneCreateMasterSceneResult> IMasterSceneService.CreateMasterSceneAsync(AllJoynMessageInfo info, IReadOnlyList<string> Scenes, string MasterSceneName, string Language)
        {
            if (string.IsNullOrEmpty(MasterSceneName))
                return Task.FromResult(MasterSceneCreateMasterSceneResult.CreateFailureResult(12)).AsAsyncOperation();

            string masterSceneId = Guid.NewGuid().ToString();
            MasterScenes.Add(masterSceneId, new MasterScene(MasterSceneName, Language, Scenes));
            SaveMasterScenes();
            MasterSceneProducer.Signals.MasterScenesCreated(new List<string> { masterSceneId });
            return Task.FromResult(MasterSceneCreateMasterSceneResult.CreateSuccessResult(0, masterSceneId)).AsAsyncOperation();
        }

        IAsyncOperation<MasterSceneDeleteMasterSceneResult> IMasterSceneService.DeleteMasterSceneAsync(AllJoynMessageInfo info, string MasterSceneID)
        {
            if (!MasterScenes.ContainsKey(MasterSceneID))
                return Task.FromResult(MasterSceneDeleteMasterSceneResult.CreateFailureResult(16)).AsAsyncOperation();
            MasterScenes.Remove(MasterSceneID);
            SaveMasterScenes();
            MasterSceneProducer.Signals.MasterScenesDeleted(new List<string> { MasterSceneID });
            return Task.FromResult(MasterSceneDeleteMasterSceneResult.CreateSuccessResult(0, MasterSceneID)).AsAsyncOperation();
        }

        IAsyncOperation<MasterSceneGetAllMasterSceneIDsResult> IMasterSceneService.GetAllMasterSceneIDsAsync(AllJoynMessageInfo info)
        {
            var sceneIds = new List<string>(MasterScenes.Keys);
            return Task.FromResult(MasterSceneGetAllMasterSceneIDsResult.CreateSuccessResult(0, sceneIds)).AsAsyncOperation();
        }

        IAsyncOperation<MasterSceneGetMasterSceneResult> IMasterSceneService.GetMasterSceneAsync(AllJoynMessageInfo info, string MasterSceneID)
        {
            if (!MasterScenes.ContainsKey(MasterSceneID))
                return Task.FromResult(MasterSceneGetMasterSceneResult.CreateFailureResult(16)).AsAsyncOperation();

            var masterScene = MasterScenes[MasterSceneID];
            return Task.FromResult(MasterSceneGetMasterSceneResult.CreateSuccessResult(0, MasterSceneID,
                masterScene.Scenes)).AsAsyncOperation();
        }

        IAsyncOperation<MasterSceneGetMasterSceneNameResult> IMasterSceneService.GetMasterSceneNameAsync(AllJoynMessageInfo info, string MasterSceneID, string Language)
        {
            if (!Scenes.ContainsKey(MasterSceneID))
                return Task.FromResult(MasterSceneGetMasterSceneNameResult.CreateFailureResult(16)).AsAsyncOperation();
            var scene = MasterScenes[MasterSceneID];
            if (scene.MasterSceneName.ContainsKey(Language))
                return Task.FromResult(MasterSceneGetMasterSceneNameResult.CreateSuccessResult(0, MasterSceneID, Language, scene.MasterSceneName[Language])).AsAsyncOperation();

            return Task.FromResult(MasterSceneGetMasterSceneNameResult.CreateFailureResult(16)).AsAsyncOperation();
        }

        IAsyncOperation<MasterSceneGetVersionResult> IMasterSceneService.GetVersionAsync(AllJoynMessageInfo info)
        {
            return Task.FromResult(MasterSceneGetVersionResult.CreateSuccessResult(InterfaceVersion)).AsAsyncOperation();
        }

        IAsyncOperation<MasterSceneSetMasterSceneNameResult> IMasterSceneService.SetMasterSceneNameAsync(AllJoynMessageInfo info, string MasterSceneID, string MasterSceneName, string Language)
        {
            if (!MasterScenes.ContainsKey(MasterSceneID))
                return Task.FromResult(MasterSceneSetMasterSceneNameResult.CreateFailureResult(16)).AsAsyncOperation();
            if (string.IsNullOrEmpty(MasterSceneName))
                return Task.FromResult(MasterSceneSetMasterSceneNameResult.CreateFailureResult(12)).AsAsyncOperation();
            var scene = MasterScenes[MasterSceneID];
            scene.MasterSceneName[Language] = MasterSceneName;
            SaveMasterScenes();
            MasterSceneProducer.Signals.MasterScenesNameChanged(new List<string> { MasterSceneID });

            return Task.FromResult(MasterSceneSetMasterSceneNameResult.CreateSuccessResult(0, MasterSceneID, Language)).AsAsyncOperation();
        }

        IAsyncOperation<MasterSceneUpdateMasterSceneResult> IMasterSceneService.UpdateMasterSceneAsync(AllJoynMessageInfo info, string MasterSceneID, IReadOnlyList<string> Scenes)
        {
            if (!MasterScenes.ContainsKey(MasterSceneID))
                return Task.FromResult(MasterSceneUpdateMasterSceneResult.CreateFailureResult(16)).AsAsyncOperation();
            var scene = MasterScenes[MasterSceneID];
            scene.Scenes = new List<string>(Scenes);
            SaveMasterScenes();
            MasterSceneProducer.Signals.MasterScenesUpdated(new List<string> { MasterSceneID });

            return Task.FromResult(MasterSceneUpdateMasterSceneResult.CreateSuccessResult(0, MasterSceneID)).AsAsyncOperation();
        }
    }
}