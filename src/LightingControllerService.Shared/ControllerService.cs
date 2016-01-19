using System;
using Windows.Devices.AllJoyn;
using Windows.Foundation;
using System.Threading.Tasks;
using System.Collections.Generic;

namespace LightingControllerService
{
    internal partial class ControllerService
    {
        private const uint InterfaceVersion = 1416;
        private AllJoynBusAttachment bus;

        public ControllerService(AllJoynBusAttachment bus)
        {
            this.bus = bus;
            ControllerServiceProducer = new org.allseen.LSF.ControllerService.ControllerServiceProducer(bus) { Service = this };
            LampProducer = new org.allseen.LSF.ControllerService.Lamp.LampProducer(bus) { Service = this };
            LoadLampGroups();
            LampGroupProducer = new org.allseen.LSF.ControllerService.LampGroup.LampGroupProducer(bus) { Service = this };
            LoadMasterScenes();
            MasterSceneProducer = new org.allseen.LSF.ControllerService.MasterScene.MasterSceneProducer(bus) { Service = this };
            LoadPresets();
            LoadDefaultLampState();
            PresetProducer = new org.allseen.LSF.ControllerService.Preset.PresetProducer(bus) { Service = this };
            SceneProducer = new org.allseen.LSF.ControllerService.Scene.SceneProducer(bus) { Service = this };
        }

        public void Start()
        {
            ControllerServiceProducer.Start();
            LampProducer.Start();
            LampGroupProducer.Start();
            MasterSceneProducer.Start();
            PresetProducer.Start();
            SceneProducer.Start();

            LightingClientService.LampFound += LightingClientService_LightFound;
            LightingClientService.LampLost += LightingClientService_LightLost;
            LightingClientService.LampStateChanged += LightingClientService_LampStateChanged;
        }

        public void Stop()
        {
            ControllerServiceProducer.Stop();
            LampGroupProducer.Stop();
            LampProducer.Stop();
            MasterSceneProducer.Stop();
            PresetProducer.Stop();
            SceneProducer.Stop();
        }

        public org.allseen.LSF.ControllerService.ControllerServiceProducer ControllerServiceProducer { get; }
        public org.allseen.LSF.ControllerService.Lamp.LampProducer LampProducer { get; }
        public org.allseen.LSF.ControllerService.LampGroup.LampGroupProducer LampGroupProducer { get; }
        public org.allseen.LSF.ControllerService.MasterScene.MasterSceneProducer MasterSceneProducer { get; }
        public org.allseen.LSF.ControllerService.Preset.PresetProducer PresetProducer { get; }
        public org.allseen.LSF.ControllerService.Scene.SceneProducer SceneProducer { get; }
    }
}