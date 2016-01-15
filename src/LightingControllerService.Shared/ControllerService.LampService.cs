using System;
using org.allseen.LSF.ControllerService;
using Windows.Devices.AllJoyn;
using Windows.Foundation;
using System.Threading.Tasks;
using org.allseen.LSF.ControllerService.Lamp;
using System.Collections.Generic;

namespace LightingControllerService
{
    internal partial class ControllerService : ILampService
    {
        IAsyncOperation<LampClearLampFaultResult> ILampService.ClearLampFaultAsync(AllJoynMessageInfo info, string interfaceMemberLampID, uint interfaceMemberLampFault)
        {
            throw new NotImplementedException();
        }

        IAsyncOperation<LampGetAllLampIDsResult> ILampService.GetAllLampIDsAsync(AllJoynMessageInfo info)
        {
            throw new NotImplementedException();
        }

        IAsyncOperation<LampGetLampDetailsResult> ILampService.GetLampDetailsAsync(AllJoynMessageInfo info, string interfaceMemberLampID)
        {
            throw new NotImplementedException();
        }

        IAsyncOperation<LampGetLampFaultsResult> ILampService.GetLampFaultsAsync(AllJoynMessageInfo info, string interfaceMemberLampID)
        {
            throw new NotImplementedException();
        }

        IAsyncOperation<LampGetLampManufacturerResult> ILampService.GetLampManufacturerAsync(AllJoynMessageInfo info, string interfaceMemberLampID, string interfaceMemberLanguage)
        {
            throw new NotImplementedException();
        }

        IAsyncOperation<LampGetLampNameResult> ILampService.GetLampNameAsync(AllJoynMessageInfo info, string interfaceMemberLampID, string interfaceMemberLanguage)
        {
            throw new NotImplementedException();
        }

        IAsyncOperation<LampGetLampParametersResult> ILampService.GetLampParametersAsync(AllJoynMessageInfo info, string interfaceMemberLampID)
        {
            throw new NotImplementedException();
        }

        IAsyncOperation<LampGetLampParametersFieldResult> ILampService.GetLampParametersFieldAsync(AllJoynMessageInfo info, string interfaceMemberLampID, string interfaceMemberLampParameterFieldName)
        {
            throw new NotImplementedException();
        }

        IAsyncOperation<LampGetLampServiceVersionResult> ILampService.GetLampServiceVersionAsync(AllJoynMessageInfo info, string interfaceMemberLampID)
        {
            throw new NotImplementedException();
        }

        IAsyncOperation<LampGetLampStateResult> ILampService.GetLampStateAsync(AllJoynMessageInfo info, string interfaceMemberLampID)
        {
            throw new NotImplementedException();
        }

        IAsyncOperation<LampGetLampStateFieldResult> ILampService.GetLampStateFieldAsync(AllJoynMessageInfo info, string interfaceMemberLampID, string interfaceMemberLampStateFieldName)
        {
            throw new NotImplementedException();
        }

        IAsyncOperation<LampGetLampSupportedLanguagesResult> ILampService.GetLampSupportedLanguagesAsync(AllJoynMessageInfo info, string interfaceMemberLampID)
        {
            throw new NotImplementedException();
        }

        IAsyncOperation<LampGetVersionResult> ILampService.GetVersionAsync(AllJoynMessageInfo info)
        {
            return Task.FromResult(LampGetVersionResult.CreateSuccessResult(InterfaceVersion)).AsAsyncOperation();
        }

        IAsyncOperation<LampPulseLampWithPresetResult> ILampService.PulseLampWithPresetAsync(AllJoynMessageInfo info, string interfaceMemberLampID, string interfaceMemberFromPresetID, string interfaceMemberToPresetID, uint interfaceMemberPeriod, uint interfaceMemberDuration, uint interfaceMemberNumPulses)
        {
            throw new NotImplementedException();
        }

        IAsyncOperation<LampPulseLampWithStateResult> ILampService.PulseLampWithStateAsync(AllJoynMessageInfo info, string interfaceMemberLampID, IReadOnlyDictionary<string, object> interfaceMemberFromLampState, IReadOnlyDictionary<string, object> interfaceMemberToLampState, uint interfaceMemberPeriod, uint interfaceMemberDuration, uint interfaceMemberNumPulses)
        {
            throw new NotImplementedException();
        }

        IAsyncOperation<LampResetLampStateResult> ILampService.ResetLampStateAsync(AllJoynMessageInfo info, string interfaceMemberLampID)
        {
            throw new NotImplementedException();
        }

        IAsyncOperation<LampResetLampStateFieldResult> ILampService.ResetLampStateFieldAsync(AllJoynMessageInfo info, string interfaceMemberLampID, string interfaceMemberLampStateFieldName)
        {
            throw new NotImplementedException();
        }

        IAsyncOperation<LampSetLampNameResult> ILampService.SetLampNameAsync(AllJoynMessageInfo info, string interfaceMemberLampID, string interfaceMemberLampName, string interfaceMemberLanguage)
        {
            throw new NotImplementedException();
        }

        IAsyncOperation<LampTransitionLampStateResult> ILampService.TransitionLampStateAsync(AllJoynMessageInfo info, string interfaceMemberLampID, IReadOnlyDictionary<string, object> interfaceMemberLampState, uint interfaceMemberTransitionPeriod)
        {
            throw new NotImplementedException();
        }

        IAsyncOperation<LampTransitionLampStateFieldResult> ILampService.TransitionLampStateFieldAsync(AllJoynMessageInfo info, string interfaceMemberLampID, string interfaceMemberLampStateFieldName, object interfaceMemberLampStateFieldValue, uint interfaceMemberTransitionPeriod)
        {
            throw new NotImplementedException();
        }

        IAsyncOperation<LampTransitionLampStateToPresetResult> ILampService.TransitionLampStateToPresetAsync(AllJoynMessageInfo info, string interfaceMemberLampID, string interfaceMemberPresetID, uint interfaceMemberTransitionPeriod)
        {
            throw new NotImplementedException();
        }
    }
}