using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace LightingControllerService
{
    internal static class LightingClientService
    {
        private static object lockLights = new object();
        private static Dictionary<string, LightingDevice> _Lights = new Dictionary<string, LightingDevice>();
        private static DeviceProviders.AllJoynProvider provider;
        static LightingClientService()
        {
            Initialize();
        }

        private static void Initialize()
        {
            provider = new DeviceProviders.AllJoynProvider();
            provider.ServiceJoined += Provider_ServiceJoined;
            provider.ServiceDropped += Provider_ServiceDropped;
            provider.Start();
        }

        public static IList<LightingDevice> Lights
        {
            get
            {
                lock (lockLights)
                    return _Lights.Values.ToList();
            }
        }
		
		public static LightingDevice GetLightById(string deviceId)
		{
			lock (lockLights)
			{
				if(_Lights.ContainsKey(deviceId))
					return _Lights[deviceId];
			}
			return null;
		}

        private static void Provider_ServiceDropped(DeviceProviders.IProvider sender, DeviceProviders.ServiceDroppedEventArgs args)
        {
            var id = args.Service.AboutData.DeviceId;
            LightingDevice device = null;
            lock (lockLights)
            {
                if (_Lights.ContainsKey(id))
                {
                    device = _Lights[id];
                    device.LampStateChanged -= Light_LampStateChanged;
                    _Lights.Remove(id);
                }
            }
            if(device != null)
            {
                System.Diagnostics.Debug.WriteLine($"Light lost: {device.DeviceId} {device.DeviceName}");
                LampLost?.Invoke(null, device);
            }
        }

        private static void Provider_ServiceJoined(DeviceProviders.IProvider sender, DeviceProviders.ServiceJoinedEventArgs args)
        {
            var device = args.Service;
            if (device.ImplementsInterface("org.allseen.LSF.LampState"))
            {
                device.JoinSession();
                var light = new LightingDevice(device);
                light.Initialize();
                lock (lockLights)
                   _Lights.Add(light.DeviceId, light);
                System.Diagnostics.Debug.WriteLine($"Light found: {light.DeviceId} {light.DeviceName}");
                LampFound?.Invoke(null, light);
                light.LampStateChanged += Light_LampStateChanged;
            }
        }

        private static void Light_LampStateChanged(object sender, IReadOnlyDictionary<string, object> args)
        {
            LampStateChanged?.Invoke(sender, args);
        }

        public static event EventHandler<LightingDevice> LampFound;
        public static event EventHandler<LightingDevice> LampLost;
        public static event EventHandler<IReadOnlyDictionary<string, object>> LampStateChanged;
    }
}
