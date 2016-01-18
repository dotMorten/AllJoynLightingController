using org.allseen.LSF.ControllerService.Lamp;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LightingControllerService.Client
{
    [Windows.UI.Xaml.Data.Bindable]
    public class Lamp
    {
        public static async Task<Lamp> CreateAsync(string id, LampConsumer consumer)
        {
            var lamp = new Lamp() { Id = id };
            var result = await consumer.GetLampNameAsync(id, "en");
            lamp.Name = result.LampName;
            return lamp;
        }
        public string Id { get; set; }
        public string Name { get; set; }
    }
}
