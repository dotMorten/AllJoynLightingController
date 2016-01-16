using org.allseen.LSF.ControllerService.Lamp;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Windows.Devices.AllJoyn;

namespace LightingControllerService
{
    internal class LightingDevice
    {
        private DeviceProviders.IService device;
        private DeviceProviders.IInterface lampState;
        private DeviceProviders.IInterface lampDetails;
        private DeviceProviders.IInterface lampParameters;
        private DeviceProviders.IInterface lampService;
        public LightingDevice(DeviceProviders.IService device)
        {
            this.device = device;
        }

        public void Initialize()
        {
            var bus = device.GetBusObjectsWhichImplementInterface("org.allseen.LSF.LampState").FirstOrDefault();
            lampState = bus?.GetInterface("org.allseen.LSF.LampState");
            bus = device.GetBusObjectsWhichImplementInterface("org.allseen.LSF.LampDetails").FirstOrDefault();
            lampDetails = bus?.GetInterface("org.allseen.LSF.LampDetails");
            bus = device.GetBusObjectsWhichImplementInterface("org.allseen.LSF.LampParameters").FirstOrDefault();
            lampParameters = bus?.GetInterface("org.allseen.LSF.LampParameters");
            bus = device.GetBusObjectsWhichImplementInterface("org.allseen.LSF.LampService").FirstOrDefault();
            lampService = bus?.GetInterface("org.allseen.LSF.LampService");
            if(lampDetails != null)
            {
                var signal = lampDetails.GetSignal("LampStateChanged");
                if(signal != null)
                {
                    signal.SignalRaised += Signal_SignalRaised;
                }
            }
        }

        private async void Signal_SignalRaised(DeviceProviders.ISignal sender, IList<object> args)
        {
            //string deviceId = (string)args[0];
            IDictionary<string, object> newstate = null;
            try {
                var state = await GetLampStateAsync();
                newstate = state.LampState;
            }
            catch
            {
                newstate = new Dictionary<string, object>();
            }
            LampStateChanged?.Invoke(this, new ReadOnlyDictionary<string, object>(newstate));
        }

        private static async Task<object> GetPropertyValueAsync(string propertyName, DeviceProviders.IInterface i)
        {
            var color = i.GetProperty(propertyName);
            if (color == null)
                return null;
            var result = await color.ReadValueAsync();
            if (result.Status.IsSuccess)
                return result.Value;
            System.Diagnostics.Debug.WriteLine($"Couldn't read {i.Name}.{propertyName} : {result.Status.StatusText}");
            return null;
        }
        private static async Task<IDictionary<string,object>> GetPropertiesAsync(DeviceProviders.IInterface i, params string[] propertyNames)
        {
            var readTask = new Dictionary<string, Task<object>>();
            foreach(var propertyName in propertyNames)
            {
                readTask[propertyName] = GetPropertyValueAsync(propertyName, i);
            }
            await Task.WhenAll(readTask.Values.ToArray()).ConfigureAwait(false);
            var propertyValues = new Dictionary<string, object>();
            foreach(var t in readTask)
            {
                if (t.Value.Result != null)
                    propertyValues[t.Key] = t.Value.Result;
            }
            return propertyValues;
        }
        private static Task<DeviceProviders.InvokeMethodResult> Execute(string methodName, DeviceProviders.IInterface i, params object[] @params)
        {
            var method = i.GetMethod(methodName);
            if(method != null)
            {
                return method.InvokeAsync(@params: new List<object>(@params)).AsTask();                
            }
            return Task.FromResult<DeviceProviders.InvokeMethodResult>(null);
        }

        public string DeviceName
        {
            get
            {
                return device.AboutData.DeviceName;
            }
        }
        public string DeviceId
        {
            get
            {
                return device.AboutData.DeviceId;
            }
        }

        public async Task<LampClearLampFaultResult> ClearLampFaultAsync(uint lampFault)
        {
            if(lampService == null)
                return LampClearLampFaultResult.CreateFailureResult(1);
            var result = await Execute("ClearLampFault", lampService, lampFault);
            if(result == null) //Method not found
                return LampClearLampFaultResult.CreateFailureResult(1);
            if (result.Status.IsFailure)
                return LampClearLampFaultResult.CreateFailureResult((int)result.Status.StatusCode);
            return LampClearLampFaultResult.CreateSuccessResult(result.Status.StatusCode, DeviceId, lampFault);
        }

        public async Task<LampGetLampDetailsResult> GetLampDetailsAsync()
        {
            if (lampDetails == null)
                return LampGetLampDetailsResult.CreateFailureResult(1);
            var result = await GetPropertiesAsync(lampDetails,
                lampDetails.Properties.Select(t => t.Name).ToArray()).ConfigureAwait(false);
            return LampGetLampDetailsResult.CreateSuccessResult(0, DeviceId, result);
        }

        public async Task<LampGetLampFaultsResult> GetLampFaultsAsync()
        {
            if (lampService == null)
                return LampGetLampFaultsResult.CreateFailureResult(1);
            var value = await GetPropertyValueAsync("LampFaults", lampService).ConfigureAwait(false);
            if (value == null)
                return LampGetLampFaultsResult.CreateFailureResult(1);
            return LampGetLampFaultsResult.CreateSuccessResult(0, DeviceId, (uint[])value);
        }

        public Task<LampGetLampManufacturerResult> GetLampManufacturerAsync(string language)
        {
            return Task.FromResult(LampGetLampManufacturerResult.CreateSuccessResult(0, DeviceId, language, device.AboutData.Manufacturer));
        }

        public Task<LampGetLampNameResult> GetLampNameAsync(string language)
        {
            return Task.FromResult(LampGetLampNameResult.CreateSuccessResult(0, DeviceId, language, DeviceName));
        }

        public async Task<LampGetLampParametersResult> GetLampParametersAsync()
        {
            if (lampParameters == null)
                return LampGetLampParametersResult.CreateFailureResult(1);
            var result = await GetPropertiesAsync(lampParameters,
                lampParameters.Properties.Select(t => t.Name).ToArray()).ConfigureAwait(false);
            return LampGetLampParametersResult.CreateSuccessResult(0, DeviceId, result);
        }

        public async Task<LampGetLampParametersFieldResult> GetLampParametersFieldAsync(string lampParameterFieldName)
        {
            if (lampParameters == null)
                return LampGetLampParametersFieldResult.CreateFailureResult(1);
            var value = await GetPropertyValueAsync(lampParameterFieldName, lampParameters).ConfigureAwait(false);
            if (value == null)
                return LampGetLampParametersFieldResult.CreateFailureResult(1);
            return LampGetLampParametersFieldResult.CreateSuccessResult(0, DeviceId, lampParameterFieldName, value);
        }

        public async Task<LampGetLampServiceVersionResult> GetLampServiceVersionAsync()
        {
            if (lampService == null)
                return LampGetLampServiceVersionResult.CreateFailureResult(1);
            var value = await GetPropertyValueAsync("LampServiceVersion", lampService).ConfigureAwait(false);
            if (value == null)
                return LampGetLampServiceVersionResult.CreateFailureResult(1);
            return LampGetLampServiceVersionResult.CreateSuccessResult(0, DeviceId, (uint)value);
        }

        public async Task<LampGetLampStateResult> GetLampStateAsync()
        {
            if (lampState == null)
                return LampGetLampStateResult.CreateFailureResult(1);
            var result = await GetPropertiesAsync(lampState,
                lampState.Properties.Select(t => t.Name).ToArray()).ConfigureAwait(false);
            return LampGetLampStateResult.CreateSuccessResult(0, DeviceId, result);
        }

        public async Task<LampGetLampStateFieldResult> GetLampStateFieldAsync(string lampStateFieldName)
        {
            if (lampState == null)
                return LampGetLampStateFieldResult.CreateFailureResult(1);
            var value = await GetPropertyValueAsync(lampStateFieldName, lampState).ConfigureAwait(false);
            if (value == null)
                return LampGetLampStateFieldResult.CreateFailureResult(1);
            return LampGetLampStateFieldResult.CreateSuccessResult(0, DeviceId, lampStateFieldName, value);
        }

        public Task<LampGetLampSupportedLanguagesResult> GetLampSupportedLanguagesAsync()
        {
            return Task.FromResult(LampGetLampSupportedLanguagesResult.CreateSuccessResult(0, DeviceId, device.AboutData.SupportedLanguages.ToList()));
        }

        public Task<LampGetVersionResult> GetVersionAsync()
        {
            var version = uint.Parse(device.AboutData.AllJoynSoftwareVersion);
            return Task.FromResult(LampGetVersionResult.CreateSuccessResult(version));
        }

        public async Task<LampPulseLampWithStateResult> PulseLampWithStateAsync(IReadOnlyDictionary<string, object> fromLampState, IReadOnlyDictionary<string, object> toLampState, uint period, uint duration, uint numPulses)
        {
            if (lampState == null)
                return LampPulseLampWithStateResult.CreateFailureResult(1);
            var result = await Execute("ApplyPulseEffect", this.lampState, 0, 
                ToObjectDictionary(fromLampState),
                ToObjectDictionary(toLampState),
                period, duration, numPulses, 0);
            if (result == null) //Method not found
                return LampPulseLampWithStateResult.CreateFailureResult(1);
            if (result.Status.IsFailure)
                return LampPulseLampWithStateResult.CreateFailureResult((int)result.Status.StatusCode);
            return LampPulseLampWithStateResult.CreateSuccessResult(result.Status.StatusCode, DeviceId);
        }

        public Task<LampSetLampNameResult> SetLampNameAsync(string lampName, string language)
        {
            //TODO
            return Task.FromResult(LampSetLampNameResult.CreateFailureResult(1));
        }


        public async Task<LampTransitionLampStateResult> TransitionLampStateAsync(IReadOnlyDictionary<string, object> lampState, uint transitionPeriod)
        {
            if (lampState == null)
                return LampTransitionLampStateResult.CreateFailureResult(1);
            var result = await Execute("TransitionLampState", this.lampState, 0, ToObjectDictionary(lampState), transitionPeriod);
            if (result == null) //Method not found
                return LampTransitionLampStateResult.CreateFailureResult(1);
            if (result.Status.IsFailure)
                return LampTransitionLampStateResult.CreateFailureResult((int)result.Status.StatusCode);
            return LampTransitionLampStateResult.CreateSuccessResult(result.Status.StatusCode, DeviceId);
        }

        private static Dictionary<object, object> ToObjectDictionary<T, S>(IEnumerable<KeyValuePair<T, S>> dictionary)
        {
            Dictionary<object, object> result = new Dictionary<object, object>();
            foreach (var item in dictionary)
                result[item.Key] = item.Value;
            return result;
        }

        public event EventHandler<IReadOnlyDictionary<string, object>> LampStateChanged;
    }
}
