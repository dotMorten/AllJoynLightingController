using org.allseen.LSF.ControllerService;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using org.allseen.LSF.ControllerService.Lamp;
using org.allseen.LSF.ControllerService.LampGroup;
using org.allseen.LSF.ControllerService.MasterScene;
using org.allseen.LSF.ControllerService.Scene;
using org.allseen.LSF.ControllerService.Preset;

namespace LightingControllerService.Client
{
    [Windows.UI.Xaml.Data.Bindable]
    public class ServiceManagerDictionary : ObservableDictionary<string, ServiceManager> {
        public ServiceManagerDictionary(Windows.UI.Core.CoreDispatcher dispatcher) : base(dispatcher) { }
    }

    [Windows.UI.Xaml.Data.Bindable]
    public class ClientManager
    {
        private object syncObject = new object();
        private Windows.UI.Core.CoreDispatcher dispatcher;
        private org.allseen.LSF.ControllerService.ControllerServiceWatcher controllerService;
        private org.allseen.LSF.ControllerService.Lamp.LampWatcher lamp;
        private org.allseen.LSF.ControllerService.LampGroup.LampGroupWatcher lampGroup;
        private org.allseen.LSF.ControllerService.MasterScene.MasterSceneWatcher masterScene;
        private org.allseen.LSF.ControllerService.Scene.SceneWatcher scene;
        private org.allseen.LSF.ControllerService.Preset.PresetWatcher preset;
        private Windows.Devices.AllJoyn.AllJoynBusAttachment bus;

        public ServiceManagerDictionary Services { get; }

        public ClientManager(Windows.UI.Core.CoreDispatcher dispatcher)
        {
            this.dispatcher = dispatcher;
            Services = new ServiceManagerDictionary(dispatcher);
            bus = new Windows.Devices.AllJoyn.AllJoynBusAttachment();
            bus.AboutData.DefaultAppName = "LightingControllerService.ClientApp";
            controllerService = new org.allseen.LSF.ControllerService.ControllerServiceWatcher(bus);
            bus = new Windows.Devices.AllJoyn.AllJoynBusAttachment();
            lamp = new org.allseen.LSF.ControllerService.Lamp.LampWatcher(bus);
            bus = new Windows.Devices.AllJoyn.AllJoynBusAttachment();
            lampGroup = new org.allseen.LSF.ControllerService.LampGroup.LampGroupWatcher(bus);
            masterScene = new org.allseen.LSF.ControllerService.MasterScene.MasterSceneWatcher(bus);
            scene = new org.allseen.LSF.ControllerService.Scene.SceneWatcher(bus);
            preset = new org.allseen.LSF.ControllerService.Preset.PresetWatcher(bus);
            controllerService.Added += ControllerService_Added;
            lamp.Added += Lamp_Added;
            lampGroup.Added += LampGroup_Added;
            masterScene.Added += MasterScene_Added;
            scene.Added += Scene_Added;
            preset.Added += Preset_Added;

            controllerService.Start();
            lamp.Start();
            lampGroup.Start();
            masterScene.Start();
            scene.Start();
            preset.Start();
        }

        private async void ControllerService_Added(org.allseen.LSF.ControllerService.ControllerServiceWatcher sender, Windows.Devices.AllJoyn.AllJoynServiceInfo args)
        {
            var id = args.UniqueName;
            ServiceManager svc = null;
            lock(syncObject)
            {
                if (!Services.ContainsKey(id))
                    Services[id] = new ServiceManager(dispatcher);
                svc = Services[id];
            }
            var consumer = await ControllerServiceConsumer.JoinSessionAsync(args, sender);
            svc.SetConsumer(consumer.Consumer);
        }
        private async void Preset_Added(org.allseen.LSF.ControllerService.Preset.PresetWatcher sender, Windows.Devices.AllJoyn.AllJoynServiceInfo args)
        {
            var id = args.UniqueName;
            ServiceManager svc = null;
            lock (syncObject)
            {
                if (!Services.ContainsKey(id))
                    Services[id] = new ServiceManager(dispatcher);
                svc = Services[id];
            }
            var consumer = await org.allseen.LSF.ControllerService.Preset.PresetConsumer.JoinSessionAsync(args, sender);
            svc.SetConsumer(consumer.Consumer);
        }

        private async void Scene_Added(org.allseen.LSF.ControllerService.Scene.SceneWatcher sender, Windows.Devices.AllJoyn.AllJoynServiceInfo args)
        {
            var id = args.UniqueName;
            ServiceManager svc = null;
            lock (syncObject)
            {
                if (!Services.ContainsKey(id))
                    Services[id] = new ServiceManager(dispatcher);
                svc = Services[id];
            }
            var consumer = await org.allseen.LSF.ControllerService.Scene.SceneConsumer.JoinSessionAsync(args, sender);
            svc.SetConsumer(consumer.Consumer);
        }

        private async void MasterScene_Added(org.allseen.LSF.ControllerService.MasterScene.MasterSceneWatcher sender, Windows.Devices.AllJoyn.AllJoynServiceInfo args)
        {
            var id = args.UniqueName;
            ServiceManager svc = null;
            lock (syncObject)
            {
                if (!Services.ContainsKey(id))
                    Services[id] = new ServiceManager(dispatcher);
                svc = Services[id];
            }
            var consumer = await org.allseen.LSF.ControllerService.MasterScene.MasterSceneConsumer.JoinSessionAsync(args, sender);
            svc.SetConsumer(consumer.Consumer);
        }

        private async void LampGroup_Added(org.allseen.LSF.ControllerService.LampGroup.LampGroupWatcher sender, Windows.Devices.AllJoyn.AllJoynServiceInfo args)
        {
            var id = args.UniqueName;
            ServiceManager svc = null;
            lock (syncObject)
            {
                if (!Services.ContainsKey(id))
                    Services[id] = new ServiceManager(dispatcher);
                svc = Services[id];
            }
            var consumer = await org.allseen.LSF.ControllerService.LampGroup.LampGroupConsumer.JoinSessionAsync(args, sender);
            svc.SetConsumer(consumer.Consumer);
        }

        private async void Lamp_Added(org.allseen.LSF.ControllerService.Lamp.LampWatcher sender, Windows.Devices.AllJoyn.AllJoynServiceInfo args)
        {
            var id = args.UniqueName;
            ServiceManager svc = null;
            lock (syncObject)
            {
                if (!Services.ContainsKey(id))
                    Services[id] = new ServiceManager(dispatcher);
                svc = Services[id];
            }
            var consumer = await org.allseen.LSF.ControllerService.Lamp.LampConsumer.JoinSessionAsync(args, sender);
            svc.SetConsumer(consumer.Consumer);
        }

    }
}
