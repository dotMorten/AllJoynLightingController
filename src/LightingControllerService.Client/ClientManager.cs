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
    public class ServiceManager
    {
        ControllerServiceConsumer controllerService;
        org.allseen.LSF.ControllerService.Lamp.LampConsumer lamp;
        org.allseen.LSF.ControllerService.LampGroup.LampGroupConsumer lampGroup;
        org.allseen.LSF.ControllerService.MasterScene.MasterSceneConsumer masterScene;
        org.allseen.LSF.ControllerService.Scene.SceneConsumer scene;
        org.allseen.LSF.ControllerService.Preset.PresetConsumer preset;
        public ServiceManager()
        {

        }
        public System.Collections.ObjectModel.ObservableCollection<string> LampIds { get; } = new System.Collections.ObjectModel.ObservableCollection<string>();
        public void SetConsumer(ControllerServiceConsumer consumer)
        {
            controllerService = consumer;
        }

        internal async void SetConsumer(LampConsumer consumer)
        {
            if(lamp != null)
            {
                lamp.Signals.LampsFoundReceived -= Signals_LampsFoundReceived;
                lamp.Signals.LampsLostReceived -= Signals_LampsLostReceived;
                LampIds.Clear();
            }
            lamp = consumer;
            if (lamp != null)
            {
                var ids = await lamp.GetAllLampIDsAsync();
                foreach (var id in ids.LampIDs)
                    LampIds.Add(id);
                lamp.Signals.LampsFoundReceived += Signals_LampsFoundReceived;
                lamp.Signals.LampsLostReceived += Signals_LampsLostReceived;
            }
        }

        private void Signals_LampsLostReceived(LampSignals sender, LampLampsLostReceivedEventArgs args)
        {
            foreach (var id in args.LampIDs)
                LampIds.Remove(id);
        }

        private void Signals_LampsFoundReceived(LampSignals sender, LampLampsFoundReceivedEventArgs args)
        {
            foreach (var id in args.LampIDs)
                LampIds.Add(id);            
        }

        internal void SetConsumer(LampGroupConsumer consumer)
        {
            lampGroup = consumer;
        }

        internal void SetConsumer(MasterSceneConsumer consumer)
        {
            masterScene = consumer;
        }

        internal void SetConsumer(SceneConsumer consumer)
        {
            scene = consumer;
        }

        internal void SetConsumer(PresetConsumer consumer)
        {
            preset = consumer;
        }
    }
    internal static class ClientManager
    {
        static object syncObject = new object();
        public static Dictionary<string, ServiceManager> Services { get; } = new Dictionary<string, ServiceManager>();
        static org.allseen.LSF.ControllerService.ControllerServiceWatcher controllerService;
        static org.allseen.LSF.ControllerService.Lamp.LampWatcher lamp;
        static org.allseen.LSF.ControllerService.LampGroup.LampGroupWatcher lampGroup;
        static org.allseen.LSF.ControllerService.MasterScene.MasterSceneWatcher masterScene;
        static org.allseen.LSF.ControllerService.Scene.SceneWatcher scene;
        static org.allseen.LSF.ControllerService.Preset.PresetWatcher preset;
        static Windows.Devices.AllJoyn.AllJoynBusAttachment bus;
        static ClientManager()
        {
            bus = new Windows.Devices.AllJoyn.AllJoynBusAttachment();
            bus.AboutData.DefaultAppName = "LightingControllerService.ClientApp";
            controllerService = new org.allseen.LSF.ControllerService.ControllerServiceWatcher(bus);
            lamp = new org.allseen.LSF.ControllerService.Lamp.LampWatcher(bus);
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

        private static async void ControllerService_Added(org.allseen.LSF.ControllerService.ControllerServiceWatcher sender, Windows.Devices.AllJoyn.AllJoynServiceInfo args)
        {
            var id = args.UniqueName;
            ServiceManager svc = null;
            lock(syncObject)
            {
                if (!Services.ContainsKey(id))
                    Services[id] = new ServiceManager();
                svc = Services[id];
            }
            var consumer = await ControllerServiceConsumer.JoinSessionAsync(args, sender);
            svc.SetConsumer(consumer.Consumer);
        }
        private static async void Preset_Added(org.allseen.LSF.ControllerService.Preset.PresetWatcher sender, Windows.Devices.AllJoyn.AllJoynServiceInfo args)
        {
            var id = args.UniqueName;
            ServiceManager svc = null;
            lock (syncObject)
            {
                if (!Services.ContainsKey(id))
                    Services[id] = new ServiceManager();
                svc = Services[id];
            }
            var consumer = await org.allseen.LSF.ControllerService.Preset.PresetConsumer.JoinSessionAsync(args, sender);
            svc.SetConsumer(consumer.Consumer);
        }

        private static async void Scene_Added(org.allseen.LSF.ControllerService.Scene.SceneWatcher sender, Windows.Devices.AllJoyn.AllJoynServiceInfo args)
        {
            var id = args.UniqueName;
            ServiceManager svc = null;
            lock (syncObject)
            {
                if (!Services.ContainsKey(id))
                    Services[id] = new ServiceManager();
                svc = Services[id];
            }
            var consumer = await org.allseen.LSF.ControllerService.Scene.SceneConsumer.JoinSessionAsync(args, sender);
            svc.SetConsumer(consumer.Consumer);
        }

        private static async void MasterScene_Added(org.allseen.LSF.ControllerService.MasterScene.MasterSceneWatcher sender, Windows.Devices.AllJoyn.AllJoynServiceInfo args)
        {
            var id = args.UniqueName;
            ServiceManager svc = null;
            lock (syncObject)
            {
                if (!Services.ContainsKey(id))
                    Services[id] = new ServiceManager();
                svc = Services[id];
            }
            var consumer = await org.allseen.LSF.ControllerService.MasterScene.MasterSceneConsumer.JoinSessionAsync(args, sender);
            svc.SetConsumer(consumer.Consumer);
        }

        private static async void LampGroup_Added(org.allseen.LSF.ControllerService.LampGroup.LampGroupWatcher sender, Windows.Devices.AllJoyn.AllJoynServiceInfo args)
        {
            var id = args.UniqueName;
            ServiceManager svc = null;
            lock (syncObject)
            {
                if (!Services.ContainsKey(id))
                    Services[id] = new ServiceManager();
                svc = Services[id];
            }
            var consumer = await org.allseen.LSF.ControllerService.LampGroup.LampGroupConsumer.JoinSessionAsync(args, sender);
            svc.SetConsumer(consumer.Consumer);
        }

        private static async void Lamp_Added(org.allseen.LSF.ControllerService.Lamp.LampWatcher sender, Windows.Devices.AllJoyn.AllJoynServiceInfo args)
        {
            var id = args.UniqueName;
            ServiceManager svc = null;
            lock (syncObject)
            {
                if (!Services.ContainsKey(id))
                    Services[id] = new ServiceManager();
                svc = Services[id];
            }
            var consumer = await org.allseen.LSF.ControllerService.Lamp.LampConsumer.JoinSessionAsync(args, sender);
            svc.SetConsumer(consumer.Consumer);
        }

    }
}
