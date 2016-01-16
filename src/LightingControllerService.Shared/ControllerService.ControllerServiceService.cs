using System;
using org.allseen.LSF.ControllerService;
using Windows.Devices.AllJoyn;
using Windows.Foundation;
using System.Threading.Tasks;
using System.Collections.Generic;

namespace LightingControllerService
{
    internal partial class ControllerService : IControllerServiceService
    {
        IAsyncOperation<ControllerServiceGetControllerServiceVersionResult> IControllerServiceService.GetControllerServiceVersionAsync(AllJoynMessageInfo info)
        {
            return Task.FromResult(ControllerServiceGetControllerServiceVersionResult.CreateSuccessResult(InterfaceVersion)).AsAsyncOperation();
        }

        IAsyncOperation<ControllerServiceGetVersionResult> IControllerServiceService.GetVersionAsync(AllJoynMessageInfo info)
        {
            return Task.FromResult(ControllerServiceGetVersionResult.CreateSuccessResult(1)).AsAsyncOperation();
        }

        IAsyncOperation<ControllerServiceLightingResetControllerServiceResult> IControllerServiceService.LightingResetControllerServiceAsync(AllJoynMessageInfo info)
        {
            Presets.Clear();
            SavePresets();
            LampGroups.Clear();
            SaveLampGroups();
            DefaultState = new Dictionary<string, object>()
            {
              { "OnOff", true },
              { "Saturation", (UInt32)0 },
              { "Brightness", UInt32.MaxValue },
              { "Hue", 0 },
              { "ColorTemp", 2800 }
            };
            //TODO: Save DefaultState
            Scenes.Clear();
            SaveScenes();
            MasterScenes.Clear();
            SaveMasterScenes();
            return Task.FromResult(ControllerServiceLightingResetControllerServiceResult.CreateSuccessResult(0)).AsAsyncOperation();
        }
    }
}