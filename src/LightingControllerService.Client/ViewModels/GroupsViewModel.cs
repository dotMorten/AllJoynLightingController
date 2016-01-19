using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LightingControllerService.Client.ViewModels
{
    public class GroupsViewModel : INotifyPropertyChanged
    {
        private static GroupsViewModel instance;
        public static GroupsViewModel Current
        {
            get
            {
                if (instance == null)
                    instance = new GroupsViewModel();
                return instance;
            }
        }
        public event PropertyChangedEventHandler PropertyChanged;
        public async Task RefreshGroupsAsync()
        {
            if (App.Client.Services.Count > 0)
            {
                var svc = App.Client.Services.FirstOrDefault();
                Groups = await svc.Value.GetGroupsAsync();
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(nameof(Groups)));
            }
        }

        public IDictionary<string, string> Groups { get; private set; }
    }
}
