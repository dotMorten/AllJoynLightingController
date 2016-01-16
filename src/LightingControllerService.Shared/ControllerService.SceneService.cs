using System;
using System.Linq;
using org.allseen.LSF.ControllerService;
using Windows.Devices.AllJoyn;
using Windows.Foundation;
using System.Threading.Tasks;
using org.allseen.LSF.ControllerService.Scene;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Text;

namespace LightingControllerService
{
    internal partial class ControllerService : ISceneService
    {
        private Dictionary<string, Scene> Scenes = new Dictionary<string, Scene>();

        public void SaveScenes()
        {
            var container = Windows.Storage.ApplicationData.Current.LocalSettings.CreateContainer("Scenes", Windows.Storage.ApplicationDataCreateDisposition.Always);
            container.Values.Clear();
            foreach (var preset in Scenes)
            {
                container.Values[preset.Key] = preset.Value.Serialize();
            }
        }

        private void LoadScenes()
        {
            var container = Windows.Storage.ApplicationData.Current.LocalSettings.CreateContainer("Scenes", Windows.Storage.ApplicationDataCreateDisposition.Always);
            foreach (var preset in container.Values)
            {
                Scenes[preset.Key] = Scene.FromString((string)preset.Value);
            }
        }

        //TODO: Make this serializable
        private class Scene
        {
            public Scene(string name, string language,
                            IReadOnlyList<SceneTransitionlampsLampGroupsToStateItem> transitionlampsLampGroupsToState,
            IReadOnlyList<SceneTransitionlampsLampGroupsToPresetItem> transitionlampsLampGroupsToPreset,
            IReadOnlyList<ScenePulselampsLampGroupsWithStateItem> pulselampsLampGroupsWithState,
            IReadOnlyList<ScenePulselampsLampGroupsWithPresetItem> pulselampsLampGroupsWithPreset)
                : this(new KeyValuePair<string, string>[] { new KeyValuePair<string, string>(language, name) }, transitionlampsLampGroupsToState, transitionlampsLampGroupsToPreset, pulselampsLampGroupsWithState, pulselampsLampGroupsWithPreset)
            {
            }
            public Scene(IEnumerable<KeyValuePair<string, string>> names,
                            IReadOnlyList<SceneTransitionlampsLampGroupsToStateItem> transitionlampsLampGroupsToState,
            IReadOnlyList<SceneTransitionlampsLampGroupsToPresetItem> transitionlampsLampGroupsToPreset,
            IReadOnlyList<ScenePulselampsLampGroupsWithStateItem> pulselampsLampGroupsWithState,
            IReadOnlyList<ScenePulselampsLampGroupsWithPresetItem> pulselampsLampGroupsWithPreset)
            {
                foreach (var lang in names)
                    SceneName[lang.Key] = lang.Value;
                TransitionlampsLampGroupsToPreset = transitionlampsLampGroupsToPreset;
                TransitionlampsLampGroupsToState = transitionlampsLampGroupsToState;
                PulselampsLampGroupsWithPreset = pulselampsLampGroupsWithPreset;
                PulselampsLampGroupsWithState = pulselampsLampGroupsWithState;
            }
            public Dictionary<string, string> SceneName { get; } = new Dictionary<string, string>();
            public IReadOnlyList<SceneTransitionlampsLampGroupsToStateItem> TransitionlampsLampGroupsToState { get; set; }
            public IReadOnlyList<SceneTransitionlampsLampGroupsToPresetItem> TransitionlampsLampGroupsToPreset { get; set; }
            public IReadOnlyList<ScenePulselampsLampGroupsWithStateItem> PulselampsLampGroupsWithState { get; set; }
            public IReadOnlyList<ScenePulselampsLampGroupsWithPresetItem> PulselampsLampGroupsWithPreset { get; set; }


            public string Serialize()
            {
                //TODO: Use JSON serialization
                StringBuilder sb = new StringBuilder();
                foreach (var l in SceneName)
                    sb.Append($"{l.Key}={l.Value}\t");

                //TODO: Save other properties
                return sb.ToString();
            }
            public static Scene FromString(string str)
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
                //TODO: Load other properties
                return new Scene(names, null, null, null, null);
            }

        }

        IAsyncOperation<SceneApplySceneResult> ISceneService.ApplySceneAsync(AllJoynMessageInfo info, string sceneID)
        {
            if(!Scenes.ContainsKey(sceneID))
                return Task.FromResult(SceneApplySceneResult.CreateFailureResult(16)).AsAsyncOperation();
            var scene = Scenes[sceneID];
            var lampsvc = (org.allseen.LSF.ControllerService.Lamp.ILampService)this;
            var lampgroupsvc = (org.allseen.LSF.ControllerService.LampGroup.ILampGroupService)this;
            foreach (var item in scene.TransitionlampsLampGroupsToState)
            {
                IList<string> lamps = item.Value1;
                IList<string> groups = item.Value2;
                var state = new ReadOnlyDictionary<string,object>(item.Value3);
                UInt32 period = item.Value4;
                foreach (var lampid in lamps)
                {
                    var _ = lampsvc.TransitionLampStateAsync(info, lampid, state, period);
                }
                foreach (var groupid in groups)
                {
                    var _ = lampgroupsvc.TransitionLampGroupStateAsync(info, groupid, state, period);
                }
            }
            foreach (var item in scene.TransitionlampsLampGroupsToPreset)
            {
                IList<string> lamps = item.Value1;
                IList<string> groups = item.Value2;
                var preset = item.Value3;
                UInt32 period = item.Value4;
                foreach (var lampid in lamps)
                {
                    var _ = lampsvc.TransitionLampStateToPresetAsync(info, lampid, preset, period);
                }
                foreach (var groupid in groups)
                {
                    var _ = lampgroupsvc.TransitionLampGroupStateToPresetAsync(info, groupid, preset, period);
                }
            }
            foreach (var item in scene.PulselampsLampGroupsWithState)
            {
                IList<string> lamps = item.Value1;
                IList<string> groups = item.Value2;
                var fromstate = new ReadOnlyDictionary<string, object>(item.Value3);
                var tostate = new ReadOnlyDictionary<string, object>(item.Value4);
                UInt32 period = item.Value5;
                UInt32 duration = item.Value6;
                UInt32 numPulses = item.Value7;
                foreach (var lampid in lamps)
                {
                    var _ = lampsvc.PulseLampWithStateAsync(info, lampid, fromstate, tostate, period, duration, numPulses);
                }
                foreach (var groupid in groups)
                {
                    var _ = lampgroupsvc.PulseLampGroupWithStateAsync(info, groupid, fromstate, tostate, period, duration, numPulses);
                }
            }
            foreach (var item in scene.PulselampsLampGroupsWithPreset)
            {
                IList<string> lamps = item.Value1;
                IList<string> groups = item.Value2;
                var frompreset = item.Value3;
                var topreset = item.Value4;
                UInt32 period = item.Value5;
                UInt32 duration = item.Value6;
                UInt32 numPulses = item.Value7;
                foreach (var lampid in lamps)
                {
                    var _ = lampsvc.PulseLampWithPresetAsync(info, lampid, frompreset, topreset, period, duration, numPulses);
                }
                foreach (var groupid in groups)
                {
                    var _ = lampgroupsvc.PulseLampGroupWithPresetAsync(info, groupid, frompreset, topreset, period, duration, numPulses);
                }
            }

            SceneProducer.Signals.ScenesApplied(new List<string> { sceneID });
            return Task.FromResult(SceneApplySceneResult.CreateSuccessResult(0, sceneID)).AsAsyncOperation();
        }

        IAsyncOperation<SceneCreateSceneResult> ISceneService.CreateSceneAsync(AllJoynMessageInfo info, 
            IReadOnlyList<SceneTransitionlampsLampGroupsToStateItem> transitionlampsLampGroupsToState, 
            IReadOnlyList<SceneTransitionlampsLampGroupsToPresetItem> transitionlampsLampGroupsToPreset, 
            IReadOnlyList<ScenePulselampsLampGroupsWithStateItem> pulselampsLampGroupsWithState, 
            IReadOnlyList<ScenePulselampsLampGroupsWithPresetItem> pulselampsLampGroupsWithPreset, 
            string sceneName, string language)
        {
            if (string.IsNullOrEmpty(sceneName))
                return Task.FromResult(SceneCreateSceneResult.CreateFailureResult(12)).AsAsyncOperation();

            string sceneID = Guid.NewGuid().ToString();
            Scenes.Add(sceneID, new Scene(sceneName, language, transitionlampsLampGroupsToState, transitionlampsLampGroupsToPreset, pulselampsLampGroupsWithState, pulselampsLampGroupsWithPreset));
            SaveScenes();
            SceneProducer.Signals.ScenesCreated(new List<string> { sceneID });
            return Task.FromResult(SceneCreateSceneResult.CreateSuccessResult(0, sceneID.ToString())).AsAsyncOperation();
        }

        IAsyncOperation<SceneDeleteSceneResult> ISceneService.DeleteSceneAsync(AllJoynMessageInfo info, string sceneID)
        {
            if (!Scenes.ContainsKey(sceneID))
                return Task.FromResult(SceneDeleteSceneResult.CreateFailureResult(16)).AsAsyncOperation();
            Scenes.Remove(sceneID);
            SaveScenes();
            SceneProducer.Signals.ScenesDeleted(new List<string> { sceneID });
            return Task.FromResult(SceneDeleteSceneResult.CreateSuccessResult(0, sceneID)).AsAsyncOperation();
        }

        IAsyncOperation<SceneGetAllSceneIDsResult> ISceneService.GetAllSceneIDsAsync(AllJoynMessageInfo info)
        {
            var sceneIds = new List<string>(Scenes.Keys);
            return Task.FromResult(SceneGetAllSceneIDsResult.CreateSuccessResult(0, sceneIds)).AsAsyncOperation();
        }

        IAsyncOperation<SceneGetSceneResult> ISceneService.GetSceneAsync(AllJoynMessageInfo info, string sceneID)
        {
            if (!Scenes.ContainsKey(sceneID))
                return Task.FromResult(SceneGetSceneResult.CreateFailureResult(16)).AsAsyncOperation();

            var scene = Scenes[sceneID];
            var transitionlampsLampGroupsToState = new List<SceneTransitionlampsLampGroupsToStateItem>();
            var transitionlampsLampGroupsToPreset = new List<SceneTransitionlampsLampGroupsToPresetItem>();
            var pulselampsLampGroupsWithState = new List<ScenePulselampsLampGroupsWithStateItem>();
            var pulselampsLampGroupsWithPreset = new List<ScenePulselampsLampGroupsWithPresetItem>();

            return Task.FromResult(SceneGetSceneResult.CreateSuccessResult(0, sceneID,
                scene.TransitionlampsLampGroupsToState.ToList(), 
                scene.TransitionlampsLampGroupsToPreset.ToList(), 
                scene.PulselampsLampGroupsWithState.ToList(), 
                scene.PulselampsLampGroupsWithPreset.ToList())).AsAsyncOperation();
        }

        IAsyncOperation<SceneGetSceneNameResult> ISceneService.GetSceneNameAsync(AllJoynMessageInfo info, string sceneID, string language)
        {
            if (!Scenes.ContainsKey(sceneID))
                return Task.FromResult(SceneGetSceneNameResult.CreateFailureResult(16)).AsAsyncOperation();
            var scene = Scenes[sceneID];
            if (scene.SceneName.ContainsKey(language))
                return Task.FromResult(SceneGetSceneNameResult.CreateSuccessResult(0, sceneID, language, scene.SceneName[language])).AsAsyncOperation();

            return Task.FromResult(SceneGetSceneNameResult.CreateFailureResult(16)).AsAsyncOperation();
            //return Task.FromResult(SceneGetSceneNameResult.CreateSuccessResult(0, sceneID, language, "SceneNameHere")).AsAsyncOperation();
        }

        IAsyncOperation<SceneGetVersionResult> ISceneService.GetVersionAsync(AllJoynMessageInfo info)
        {
            return Task.FromResult(SceneGetVersionResult.CreateSuccessResult(InterfaceVersion)).AsAsyncOperation();
        }

        IAsyncOperation<SceneSetSceneNameResult> ISceneService.SetSceneNameAsync(AllJoynMessageInfo info, string sceneID, string sceneName, string language)
        {
            if (!Scenes.ContainsKey(sceneID))
                return Task.FromResult(SceneSetSceneNameResult.CreateFailureResult(16)).AsAsyncOperation();
            if (string.IsNullOrEmpty(sceneName))
                return Task.FromResult(SceneSetSceneNameResult.CreateFailureResult(12)).AsAsyncOperation();
            var scene = Scenes[sceneID];
            scene.SceneName[language] = sceneName;
            SaveScenes();
            SceneProducer.Signals.ScenesNameChanged(new List<string> { sceneID });

            return Task.FromResult(SceneSetSceneNameResult.CreateSuccessResult(0, sceneID, language)).AsAsyncOperation();
        }

        IAsyncOperation<SceneUpdateSceneResult> ISceneService.UpdateSceneAsync(AllJoynMessageInfo info, string sceneID, 
            IReadOnlyList<SceneTransitionlampsLampGroupsToStateItem> transitionlampsLampGroupsToState, 
            IReadOnlyList<SceneTransitionlampsLampGroupsToPresetItem> transitionlampsLampGroupsToPreset,
            IReadOnlyList<ScenePulselampsLampGroupsWithStateItem> pulselampsLampGroupsWithState,
            IReadOnlyList<ScenePulselampsLampGroupsWithPresetItem> pulselampsLampGroupsWithPreset)
        {
            if (!Scenes.ContainsKey(sceneID))
                return Task.FromResult(SceneUpdateSceneResult.CreateFailureResult(16)).AsAsyncOperation();
            var scene = Scenes[sceneID];
            scene.PulselampsLampGroupsWithPreset = pulselampsLampGroupsWithPreset;
            scene.PulselampsLampGroupsWithState = pulselampsLampGroupsWithState;
            scene.TransitionlampsLampGroupsToPreset = transitionlampsLampGroupsToPreset;
            scene.TransitionlampsLampGroupsToState = transitionlampsLampGroupsToState;
            SaveScenes();
            SceneProducer.Signals.ScenesUpdated(new List<string> { sceneID });

            return Task.FromResult(SceneUpdateSceneResult.CreateSuccessResult(0, sceneID)).AsAsyncOperation();
        }
    }
}