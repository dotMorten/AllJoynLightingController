using System;
using org.allseen.LSF.ControllerService;
using Windows.Devices.AllJoyn;
using Windows.Foundation;
using System.Threading.Tasks;
using org.allseen.LSF.ControllerService.MasterScene;
using System.Collections.Generic;

namespace LightingControllerService
{
    internal partial class ControllerService : IMasterSceneService
    {
        IAsyncOperation<MasterSceneApplyMasterSceneResult> IMasterSceneService.ApplyMasterSceneAsync(AllJoynMessageInfo info, string interfaceMemberMasterSceneID)
        {
            throw new NotImplementedException();
        }

        IAsyncOperation<MasterSceneCreateMasterSceneResult> IMasterSceneService.CreateMasterSceneAsync(AllJoynMessageInfo info, IReadOnlyList<string> interfaceMemberScenes, string interfaceMemberMasterSceneName, string interfaceMemberLanguage)
        {
            throw new NotImplementedException();
        }

        IAsyncOperation<MasterSceneDeleteMasterSceneResult> IMasterSceneService.DeleteMasterSceneAsync(AllJoynMessageInfo info, string interfaceMemberMasterSceneID)
        {
            throw new NotImplementedException();
        }

        IAsyncOperation<MasterSceneGetAllMasterSceneIDsResult> IMasterSceneService.GetAllMasterSceneIDsAsync(AllJoynMessageInfo info)
        {
            throw new NotImplementedException();
        }

        IAsyncOperation<MasterSceneGetMasterSceneResult> IMasterSceneService.GetMasterSceneAsync(AllJoynMessageInfo info, string interfaceMemberMasterSceneID)
        {
            throw new NotImplementedException();
        }

        IAsyncOperation<MasterSceneGetMasterSceneNameResult> IMasterSceneService.GetMasterSceneNameAsync(AllJoynMessageInfo info, string interfaceMemberMasterSceneID, string interfaceMemberLanguage)
        {
            throw new NotImplementedException();
        }

        IAsyncOperation<MasterSceneGetVersionResult> IMasterSceneService.GetVersionAsync(AllJoynMessageInfo info)
        {
            return Task.FromResult(MasterSceneGetVersionResult.CreateSuccessResult(InterfaceVersion)).AsAsyncOperation();
        }

        IAsyncOperation<MasterSceneSetMasterSceneNameResult> IMasterSceneService.SetMasterSceneNameAsync(AllJoynMessageInfo info, string interfaceMemberMasterSceneID, string interfaceMemberMasterSceneName, string interfaceMemberLanguage)
        {
            throw new NotImplementedException();
        }

        IAsyncOperation<MasterSceneUpdateMasterSceneResult> IMasterSceneService.UpdateMasterSceneAsync(AllJoynMessageInfo info, string interfaceMemberMasterSceneID, IReadOnlyList<string> interfaceMemberScenes)
        {
            throw new NotImplementedException();
        }
    }
}