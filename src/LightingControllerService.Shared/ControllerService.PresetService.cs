using System;
using org.allseen.LSF.ControllerService;
using Windows.Devices.AllJoyn;
using Windows.Foundation;
using System.Threading.Tasks;
using org.allseen.LSF.ControllerService.Preset;
using System.Collections.Generic;

namespace LightingControllerService
{
    internal partial class ControllerService : IPresetService
    {
        IAsyncOperation<PresetCreatePresetResult> IPresetService.CreatePresetAsync(AllJoynMessageInfo info, IReadOnlyDictionary<string, object> interfaceMemberLampState, string interfaceMemberPresetName, string interfaceMemberLanguage)
        {
            throw new NotImplementedException();
        }

        IAsyncOperation<PresetDeletePresetResult> IPresetService.DeletePresetAsync(AllJoynMessageInfo info, string interfaceMemberPresetID)
        {
            throw new NotImplementedException();
        }

        IAsyncOperation<PresetGetAllPresetIDsResult> IPresetService.GetAllPresetIDsAsync(AllJoynMessageInfo info)
        {
            throw new NotImplementedException();
        }

        IAsyncOperation<PresetGetDefaultLampStateResult> IPresetService.GetDefaultLampStateAsync(AllJoynMessageInfo info)
        {
            throw new NotImplementedException();
        }

        IAsyncOperation<PresetGetPresetResult> IPresetService.GetPresetAsync(AllJoynMessageInfo info, string interfaceMemberPresetID)
        {
            throw new NotImplementedException();
        }

        IAsyncOperation<PresetGetPresetNameResult> IPresetService.GetPresetNameAsync(AllJoynMessageInfo info, string interfaceMemberPresetID, string interfaceMemberLanguage)
        {
            throw new NotImplementedException();
        }

        IAsyncOperation<PresetGetVersionResult> IPresetService.GetVersionAsync(AllJoynMessageInfo info)
        {
            return Task.FromResult(PresetGetVersionResult.CreateSuccessResult(InterfaceVersion)).AsAsyncOperation();
        }

        IAsyncOperation<PresetSetDefaultLampStateResult> IPresetService.SetDefaultLampStateAsync(AllJoynMessageInfo info, IReadOnlyDictionary<string, object> interfaceMemberLampState)
        {
            throw new NotImplementedException();
        }

        IAsyncOperation<PresetSetPresetNameResult> IPresetService.SetPresetNameAsync(AllJoynMessageInfo info, string interfaceMemberPresetID, string interfaceMemberPresetName, string interfaceMemberLanguage)
        {
            throw new NotImplementedException();
        }

        IAsyncOperation<PresetUpdatePresetResult> IPresetService.UpdatePresetAsync(AllJoynMessageInfo info, string interfaceMemberPresetID, IReadOnlyDictionary<string, object> interfaceMemberLampState)
        {
            throw new NotImplementedException();
        }
    }
}