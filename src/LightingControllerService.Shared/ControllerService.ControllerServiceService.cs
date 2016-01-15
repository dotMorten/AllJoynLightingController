using System;
using org.allseen.LSF.ControllerService;
using Windows.Devices.AllJoyn;
using Windows.Foundation;
using System.Threading.Tasks;

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
            //TODO: Perform the reset
            return Task.FromResult(ControllerServiceLightingResetControllerServiceResult.CreateSuccessResult(0)).AsAsyncOperation();
        }
    }
}