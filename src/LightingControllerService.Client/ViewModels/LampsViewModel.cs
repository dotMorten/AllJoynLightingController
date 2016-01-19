using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LightingControllerService.Client.ViewModels
{
    public class LampsViewModel : INotifyPropertyChanged
    {
        private static LampsViewModel instance;
        public static LampsViewModel Current
        {
            get
            {
                if (instance == null)
                    instance = new LampsViewModel();
                return instance;
            }
        }
        public event PropertyChangedEventHandler PropertyChanged;
        public void RefreshLamps()
        {
            if (App.Client.Services.Count > 0)
            {
                var svc = App.Client.Services.FirstOrDefault();
                Lamps = svc.Value.GetLamps();
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(nameof(Lamps)));
            }
        }

        public IList<Lamp> Lamps { get; private set; }
    }
}
