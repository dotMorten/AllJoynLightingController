using System;
using System.Linq;
using Windows.Devices.AllJoyn;
using Windows.Foundation;
using System.Threading.Tasks;
using org.allseen.LSF.ControllerService.Lamp;
using System.Collections.Generic;

namespace LightingControllerService
{
    internal partial class ControllerService : ILampService
    {
        private void LightingClientService_LightLost(object sender, LightingDevice e)
        {
            LampProducer.Signals.LampsLost(new List<string>() { e.DeviceId }.AsReadOnly());
        }

        private void LightingClientService_LightFound(object sender, LightingDevice e)
        {
            LampProducer.Signals.LampsFound(new List<string>() { e.DeviceId }.AsReadOnly());
        }
        private void LightingClientService_LampStateChanged(object sender, IReadOnlyDictionary<string,object> state)
        {
            var device = (LightingDevice)sender;
            LampProducer.Signals.LampStateChanged(device.DeviceId, state);
        }



        IAsyncOperation<LampGetAllLampIDsResult> ILampService.GetAllLampIDsAsync(AllJoynMessageInfo info)
        {
            return Task.FromResult(
               LampGetAllLampIDsResult.CreateSuccessResult(0, LightingClientService.Lights.Select(l => l.DeviceId).ToList())
            ).AsAsyncOperation();
        }

        IAsyncOperation<LampGetVersionResult> ILampService.GetVersionAsync(AllJoynMessageInfo info)
        {
            return Task.FromResult(LampGetVersionResult.CreateSuccessResult(InterfaceVersion)).AsAsyncOperation();
        }

        IAsyncOperation<LampClearLampFaultResult> ILampService.ClearLampFaultAsync(AllJoynMessageInfo info, string lampID, uint lampFault)
        {
            var light = LightingClientService.GetLightById(lampID);
            if (light == null)
                return Task.FromResult(LampClearLampFaultResult.CreateFailureResult(16)).AsAsyncOperation();
            return light.ClearLampFaultAsync(lampFault).AsAsyncOperation();
        }

        IAsyncOperation<LampGetLampDetailsResult> ILampService.GetLampDetailsAsync(AllJoynMessageInfo info, string lampID)
        {
            var light = LightingClientService.GetLightById(lampID);
            if (light == null)
                return Task.FromResult(LampGetLampDetailsResult.CreateFailureResult(16)).AsAsyncOperation();
            return light.GetLampDetailsAsync().AsAsyncOperation();
        }

        IAsyncOperation<LampGetLampFaultsResult> ILampService.GetLampFaultsAsync(AllJoynMessageInfo info, string lampID)
        {
            var light = LightingClientService.GetLightById(lampID);
            if (light == null)
                return Task.FromResult(LampGetLampFaultsResult.CreateFailureResult(16)).AsAsyncOperation();
            return light.GetLampFaultsAsync().AsAsyncOperation();
        }

        IAsyncOperation<LampGetLampManufacturerResult> ILampService.GetLampManufacturerAsync(AllJoynMessageInfo info, string lampID, string Language)
        {
            var light = LightingClientService.GetLightById(lampID);
            if (light == null)
                return Task.FromResult(LampGetLampManufacturerResult.CreateFailureResult(16)).AsAsyncOperation();
            return light.GetLampManufacturerAsync(Language).AsAsyncOperation();
        }

        IAsyncOperation<LampGetLampNameResult> ILampService.GetLampNameAsync(AllJoynMessageInfo info, string lampID, string Language)
        {
            var light = LightingClientService.GetLightById(lampID);
            if (light == null)
                return Task.FromResult(LampGetLampNameResult.CreateFailureResult(16)).AsAsyncOperation();
            return light.GetLampNameAsync(Language).AsAsyncOperation();
        }

        IAsyncOperation<LampGetLampParametersResult> ILampService.GetLampParametersAsync(AllJoynMessageInfo info, string lampID)
        {
            var light = LightingClientService.GetLightById(lampID);
            if (light == null)
                return Task.FromResult(LampGetLampParametersResult.CreateFailureResult(16)).AsAsyncOperation();
            return light.GetLampParametersAsync().AsAsyncOperation();
        }

        IAsyncOperation<LampGetLampParametersFieldResult> ILampService.GetLampParametersFieldAsync(AllJoynMessageInfo info, string lampID, string LampParameterFieldName)
        {
            var light = LightingClientService.GetLightById(lampID);
            if (light == null)
                return Task.FromResult(LampGetLampParametersFieldResult.CreateFailureResult(16)).AsAsyncOperation();
            return light.GetLampParametersFieldAsync(LampParameterFieldName).AsAsyncOperation();
        }

        IAsyncOperation<LampGetLampServiceVersionResult> ILampService.GetLampServiceVersionAsync(AllJoynMessageInfo info, string lampID)
        {
            var light = LightingClientService.GetLightById(lampID);
            if (light == null)
                return Task.FromResult(LampGetLampServiceVersionResult.CreateFailureResult(16)).AsAsyncOperation();
            return light.GetLampServiceVersionAsync().AsAsyncOperation();
        }

        IAsyncOperation<LampGetLampStateResult> ILampService.GetLampStateAsync(AllJoynMessageInfo info, string lampID)
        {
            var light = LightingClientService.GetLightById(lampID);
            if (light == null)
                return Task.FromResult(LampGetLampStateResult.CreateFailureResult(16)).AsAsyncOperation();
            return light.GetLampStateAsync().AsAsyncOperation();
        }

        IAsyncOperation<LampGetLampStateFieldResult> ILampService.GetLampStateFieldAsync(AllJoynMessageInfo info, string lampID, string LampStateFieldName)
        {
            var light = LightingClientService.GetLightById(lampID);
            if (light == null)
                return Task.FromResult(LampGetLampStateFieldResult.CreateFailureResult(16)).AsAsyncOperation();
            return light.GetLampStateFieldAsync(LampStateFieldName).AsAsyncOperation();
        }

        IAsyncOperation<LampGetLampSupportedLanguagesResult> ILampService.GetLampSupportedLanguagesAsync(AllJoynMessageInfo info, string lampID)
        {
            var light = LightingClientService.GetLightById(lampID);
            if (light == null)
                return Task.FromResult(LampGetLampSupportedLanguagesResult.CreateFailureResult(16)).AsAsyncOperation();
            return light.GetLampSupportedLanguagesAsync().AsAsyncOperation();
        }

        IAsyncOperation<LampPulseLampWithPresetResult> ILampService.PulseLampWithPresetAsync(AllJoynMessageInfo info, string lampID, string FromPresetID, string ToPresetID, uint Period, uint Duration, uint NumPulses)
        {
            var light = LightingClientService.GetLightById(lampID);
            if (light == null)
                return Task.FromResult(LampPulseLampWithPresetResult.CreateFailureResult(16)).AsAsyncOperation();
            if (!Presets.ContainsKey(FromPresetID) || !Presets.ContainsKey(ToPresetID))
            {
                return Task.FromResult(LampPulseLampWithPresetResult.CreateFailureResult(16)).AsAsyncOperation();
            }
            var fromState = Presets[FromPresetID].State;
            var toState = Presets[ToPresetID].State;
            return light.PulseLampWithStateAsync(fromState, toState, Period, Duration, NumPulses).ContinueWith(r =>
            {
                if (r.Result.Status > 0)
                    return LampPulseLampWithPresetResult.CreateFailureResult(r.Result.Status);
                return LampPulseLampWithPresetResult.CreateSuccessResult(r.Result.ResponseCode, lampID);
            }).AsAsyncOperation();
        }

        IAsyncOperation<LampPulseLampWithStateResult> ILampService.PulseLampWithStateAsync(AllJoynMessageInfo info, string lampID, IReadOnlyDictionary<string, object> FromLampState, IReadOnlyDictionary<string, object> ToLampState, uint Period, uint Duration, uint NumPulses)
        {
            var light = LightingClientService.GetLightById(lampID);
            if (light == null)
                return Task.FromResult(LampPulseLampWithStateResult.CreateFailureResult(16)).AsAsyncOperation();
            return light.PulseLampWithStateAsync(FromLampState, ToLampState, Period, Duration, NumPulses).AsAsyncOperation();
        }

        IAsyncOperation<LampResetLampStateResult> ILampService.ResetLampStateAsync(AllJoynMessageInfo info, string lampID)
        {
            var light = LightingClientService.GetLightById(lampID);
            if (light == null)
                return Task.FromResult(LampResetLampStateResult.CreateFailureResult(16)).AsAsyncOperation();
            return light.TransitionLampStateAsync(DefaultLampState, 200).ContinueWith(r =>
            {
                if (r.Result.Status > 0)
                    return LampResetLampStateResult.CreateFailureResult(r.Result.Status);
                return LampResetLampStateResult.CreateSuccessResult(r.Result.ResponseCode, lampID);
            }).AsAsyncOperation();
        }

        IAsyncOperation<LampResetLampStateFieldResult> ILampService.ResetLampStateFieldAsync(AllJoynMessageInfo info, string lampID, string LampStateFieldName)
        {
            var light = LightingClientService.GetLightById(lampID);
            if (light == null)
                return Task.FromResult(LampResetLampStateFieldResult.CreateFailureResult(16)).AsAsyncOperation();
            if (DefaultLampState.ContainsKey(LampStateFieldName))
                return Task.FromResult(LampResetLampStateFieldResult.CreateSuccessResult(0, lampID, LampStateFieldName)).AsAsyncOperation();
            Dictionary<string, object> state = new Dictionary<string, object>() { { LampStateFieldName, DefaultLampState[LampStateFieldName] } };
            return light.TransitionLampStateAsync(state, 200).ContinueWith(r =>
            {
                if (r.Result.Status > 0)
                    return LampResetLampStateFieldResult.CreateFailureResult(r.Result.Status);
                return LampResetLampStateFieldResult.CreateSuccessResult(r.Result.ResponseCode, lampID, LampStateFieldName);
            }).AsAsyncOperation();
        }

        IAsyncOperation<LampSetLampNameResult> ILampService.SetLampNameAsync(AllJoynMessageInfo info, string lampID, string LampName, string Language)
        {
            var light = LightingClientService.GetLightById(lampID);
            if (light == null)
                return Task.FromResult(LampSetLampNameResult.CreateFailureResult(16)).AsAsyncOperation();
            return light.SetLampNameAsync(LampName, Language).AsAsyncOperation();
        }

        IAsyncOperation<LampTransitionLampStateResult> ILampService.TransitionLampStateAsync(AllJoynMessageInfo info, string lampID, IReadOnlyDictionary<string, object> LampState, uint TransitionPeriod)
        {
            var light = LightingClientService.GetLightById(lampID);
            if (light == null)
                return Task.FromResult(LampTransitionLampStateResult.CreateFailureResult(16)).AsAsyncOperation();
            return light.TransitionLampStateAsync(LampState, TransitionPeriod).AsAsyncOperation();
        }

        IAsyncOperation<LampTransitionLampStateFieldResult> ILampService.TransitionLampStateFieldAsync(AllJoynMessageInfo info, string lampID, string LampStateFieldName, object LampStateFieldValue, uint TransitionPeriod)
        {
            var light = LightingClientService.GetLightById(lampID);
            if (light == null)
                return Task.FromResult(LampTransitionLampStateFieldResult.CreateFailureResult(16)).AsAsyncOperation();
            Dictionary<string, object> parameters = new Dictionary<string, object>();
            parameters[LampStateFieldName] = LampStateFieldValue;
            return light.TransitionLampStateAsync(new System.Collections.ObjectModel.ReadOnlyDictionary<string, object>(parameters), TransitionPeriod).ContinueWith(r =>
             {
                 if (r.Result.Status > 0)
                     return LampTransitionLampStateFieldResult.CreateFailureResult(r.Result.Status);
                 return LampTransitionLampStateFieldResult.CreateSuccessResult(r.Result.ResponseCode, lampID, LampStateFieldName);
             }).AsAsyncOperation();
        }

        IAsyncOperation<LampTransitionLampStateToPresetResult> ILampService.TransitionLampStateToPresetAsync(AllJoynMessageInfo info, string lampID, string PresetID, uint transitionPeriod)
        {
            var light = LightingClientService.GetLightById(lampID);
            if (light == null)
                return Task.FromResult(LampTransitionLampStateToPresetResult.CreateFailureResult(16)).AsAsyncOperation();
            if (!Presets.ContainsKey(PresetID))
            {
                return Task.FromResult(LampTransitionLampStateToPresetResult.CreateFailureResult(16)).AsAsyncOperation();
            }
            var fromState = Presets[PresetID].State;
            return light.TransitionLampStateAsync(fromState, transitionPeriod).ContinueWith(r =>
            {
                if (r.Result.Status > 0)
                    return LampTransitionLampStateToPresetResult.CreateFailureResult(r.Result.Status);
                return LampTransitionLampStateToPresetResult.CreateSuccessResult(r.Result.ResponseCode, lampID);
            }).AsAsyncOperation();
        }
    }
}