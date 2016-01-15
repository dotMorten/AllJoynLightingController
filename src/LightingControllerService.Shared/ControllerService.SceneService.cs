using System;
using System.Linq;
using org.allseen.LSF.ControllerService;
using Windows.Devices.AllJoyn;
using Windows.Foundation;
using System.Threading.Tasks;
using org.allseen.LSF.ControllerService.Scene;
using System.Collections.Generic;

namespace LightingControllerService
{
    internal partial class ControllerService : ISceneService
    {
        //TODO: Save this dictionary on update/add/delete
        private Dictionary<string, Scene> Scenes = new Dictionary<string, Scene>();
        //TODO: Make this serializable
        private class Scene
        {
            public Scene(string name, string language,
                            IReadOnlyList<SceneTransitionlampsLampGroupsToStateItem> transitionlampsLampGroupsToState,
            IReadOnlyList<SceneTransitionlampsLampGroupsToPresetItem> transitionlampsLampGroupsToPreset,
            IReadOnlyList<ScenePulselampsLampGroupsWithStateItem> pulselampsLampGroupsWithState,
            IReadOnlyList<ScenePulselampsLampGroupsWithPresetItem> pulselampsLampGroupsWithPreset)
            {
                SceneName[language] = name;
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

        }

        IAsyncOperation<SceneApplySceneResult> ISceneService.ApplySceneAsync(AllJoynMessageInfo info, string sceneID)
        {
            if(!Scenes.ContainsKey(sceneID))
                return Task.FromResult(SceneApplySceneResult.CreateFailureResult(16)).AsAsyncOperation();

            var scene = Scenes[sceneID];
            foreach(var item in scene.PulselampsLampGroupsWithPreset)
            {
            }
            //todo: apply scene

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
            SceneProducer.Signals.ScenesCreated(new List<string> { sceneID });
            return Task.FromResult(SceneCreateSceneResult.CreateSuccessResult(0, sceneID.ToString())).AsAsyncOperation();
        }

        IAsyncOperation<SceneDeleteSceneResult> ISceneService.DeleteSceneAsync(AllJoynMessageInfo info, string sceneID)
        {
            if (!Scenes.ContainsKey(sceneID))
                return Task.FromResult(SceneDeleteSceneResult.CreateFailureResult(16)).AsAsyncOperation();
            Scenes.Remove(sceneID);
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
            SceneProducer.Signals.ScenesUpdated(new List<string> { sceneID });

            return Task.FromResult(SceneUpdateSceneResult.CreateSuccessResult(0, sceneID)).AsAsyncOperation();
        }
    }
}