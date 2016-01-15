using System;
using System.Collections.Generic;
using System.Text;

namespace LightingControllerService
{
    internal static class ControllerServiceHandler
    {
        private static Windows.Devices.AllJoyn.AllJoynBusAttachment bus;
        private static ControllerService service;

        public static void Initialize()
        {
            bus = new Windows.Devices.AllJoyn.AllJoynBusAttachment();

            bus.AboutData.DefaultAppName = "AllJoyn Lighting Service Controller";
            bus.AboutData.DefaultManufacturer = "Morten Nielsen";
            bus.AboutData.DefaultDescription = "Lighting Service for AllJoyn";
            bus.AboutData.ModelNumber = "Model Number here";
            service = new ControllerService(bus);

            service.Start();
        }
    }
}
