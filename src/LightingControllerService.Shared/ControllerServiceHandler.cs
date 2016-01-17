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

            bus.AboutData.DefaultAppName = "Lighting Controller Service";
            bus.AboutData.DefaultManufacturer = "Morten Nielsen";
            bus.AboutData.DefaultDescription = "Lighting Controller Service for AllJoyn";
            bus.AboutData.ModelNumber = "Controller 1.0";
            service = new ControllerService(bus);

            service.Start();
        }
    }
}
