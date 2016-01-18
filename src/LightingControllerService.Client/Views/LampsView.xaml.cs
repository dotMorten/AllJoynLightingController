using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Threading.Tasks;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

namespace LightingControllerService.Client.Views
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class LampsView : Page
    {
        public LampsView()
        {
            this.InitializeComponent();
            //ServiceClient.Services
            //ServiceClient.Services.MapChanged += Services_MapChanged;
            //ServiceClient = App.Client;
            Test();
        }

        private void Services_MapChanged(IObservableMap<string, ServiceManager> sender, IMapChangedEventArgs<string> @event)
        {
        }

        private void Services_CollectionChanged(object sender, System.Collections.Specialized.NotifyCollectionChangedEventArgs e)
        {
        }

        private async void Test()
        {
            DataContext = ServiceClient;
            await Task.Delay(5000);
            DataContext = null;
            DataContext = ServiceClient;
        }

        public ClientManager ServiceClient { get; }
    }
}
