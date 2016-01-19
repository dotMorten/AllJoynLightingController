using org.allseen.LSF.ControllerService;
using org.allseen.LSF.ControllerService.Lamp;
using org.allseen.LSF.ControllerService.LampGroup;
using org.allseen.LSF.ControllerService.MasterScene;
using org.allseen.LSF.ControllerService.Preset;
using org.allseen.LSF.ControllerService.Scene;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LightingControllerService.Client
{
    [Windows.UI.Xaml.Data.Bindable]
    public class ServiceManager
    {
        private Windows.UI.Core.CoreDispatcher dispatcher;
        private ControllerServiceConsumer controllerService;
        private LampConsumer lamp;
        private LampGroupConsumer lampGroup;
        private MasterSceneConsumer masterScene;
        private SceneConsumer scene;
        private PresetConsumer preset;

        public ServiceManager(Windows.UI.Core.CoreDispatcher dispatcher)
        {
            this.dispatcher = dispatcher;
            Lamps = new ObservableDictionary<string, Lamp>(dispatcher);
        }

        public ObservableDictionary<string, Lamp> Lamps { get; }

        public void SetConsumer(ControllerServiceConsumer consumer)
        {
            controllerService = consumer;
        }

        internal async void SetConsumer(LampConsumer consumer)
        {
            if (lamp != null)
            {
                lamp.Signals.LampsFoundReceived -= Signals_LampsFoundReceived;
                lamp.Signals.LampsLostReceived -= Signals_LampsLostReceived;
                Lamps.Clear();
            }
            lamp = consumer;
            if (lamp != null)
            {
                var ids = await lamp.GetAllLampIDsAsync();
                foreach (var id in ids.LampIDs)
                {
                    var l = await Lamp.CreateAsync(id, consumer);
                    Lamps.Add(id, l);
                    System.Diagnostics.Debug.WriteLine($"Found lamp {l.Name}");
                }
                lamp.Signals.LampsFoundReceived += Signals_LampsFoundReceived;
                lamp.Signals.LampsLostReceived += Signals_LampsLostReceived;
            }
        }


        private void Signals_LampsLostReceived(LampSignals sender, LampLampsLostReceivedEventArgs args)
        {
            foreach (var id in args.LampIDs)
                Lamps.Remove(id);
        }

        private async void Signals_LampsFoundReceived(LampSignals sender, LampLampsFoundReceivedEventArgs args)
        {
            foreach (var id in args.LampIDs)
            {
                var l = await Lamp.CreateAsync(id, lamp);
                Lamps.Add(id, l);
                System.Diagnostics.Debug.WriteLine($"Found lamp {l.Name}");
            }
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

        public async Task<Dictionary<string,string>> GetGroupsAsync()
        {
            Dictionary<string, string> result = new Dictionary<string, string>();
            if (lampGroup != null)
            {
                var ids = await lampGroup.GetAllLampGroupIDsAsync();
                foreach (var id in ids.LampGroupIDs)
                {
                    var name = await lampGroup.GetLampGroupNameAsync(id, "en");
                    result[id] = name.LampGroupName;
                }
            }
            return result;
        }
        public IList<Lamp> GetLamps()
        {
            Dictionary<string, string> result = new Dictionary<string, string>();
            return Lamps.Values.ToList();
        }
    }
}
