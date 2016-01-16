//-----------------------------------------------------------------------------
// <auto-generated> 
//   This code was generated by a tool. 
// 
//   Changes to this file may cause incorrect behavior and will be lost if  
//   the code is regenerated.
//
//   Tool: AllJoynCodeGenerator.exe
//
//   This tool is located in the Windows 10 SDK and the Windows 10 AllJoyn 
//   Visual Studio Extension in the Visual Studio Gallery.  
//
//   The generated code should be packaged in a Windows 10 C++/CX Runtime  
//   Component which can be consumed in any UWP-supported language using 
//   APIs that are available in Windows.Devices.AllJoyn.
//
//   Using AllJoynCodeGenerator - Invoke the following command with a valid 
//   Introspection XML file and a writable output directory:
//     AllJoynCodeGenerator -i <INPUT XML FILE> -o <OUTPUT DIRECTORY>
// </auto-generated>
//-----------------------------------------------------------------------------
#include "pch.h"

using namespace Microsoft::WRL;
using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::Devices::AllJoyn;
using namespace org::allseen::LSF::ControllerService::Preset;

// Note: Unlike an Interface implementation, which provides a single handler for each member, the event
// model allows for 0 or more listeners to be registered. The EventAdapter implementation deals with this
// difference by implementing a last-writer-wins policy. The lack of any return value (i.e., 0 listeners)
// is handled by returning a null result.

// Methods
IAsyncOperation<PresetGetDefaultLampStateResult^>^ PresetServiceEventAdapter::GetDefaultLampStateAsync(_In_ AllJoynMessageInfo^ info)
{
    auto args = ref new PresetGetDefaultLampStateCalledEventArgs(info);
    GetDefaultLampStateCalled(this, args);
    return PresetGetDefaultLampStateCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<PresetSetDefaultLampStateResult^>^ PresetServiceEventAdapter::SetDefaultLampStateAsync(_In_ AllJoynMessageInfo^ info, _In_ Windows::Foundation::Collections::IMapView<Platform::String^,Platform::Object^>^ interfaceMemberLampState)
{
    auto args = ref new PresetSetDefaultLampStateCalledEventArgs(info, interfaceMemberLampState);
    SetDefaultLampStateCalled(this, args);
    return PresetSetDefaultLampStateCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<PresetGetAllPresetIDsResult^>^ PresetServiceEventAdapter::GetAllPresetIDsAsync(_In_ AllJoynMessageInfo^ info)
{
    auto args = ref new PresetGetAllPresetIDsCalledEventArgs(info);
    GetAllPresetIDsCalled(this, args);
    return PresetGetAllPresetIDsCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<PresetGetPresetNameResult^>^ PresetServiceEventAdapter::GetPresetNameAsync(_In_ AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberPresetID, _In_ Platform::String^ interfaceMemberLanguage)
{
    auto args = ref new PresetGetPresetNameCalledEventArgs(info, interfaceMemberPresetID, interfaceMemberLanguage);
    GetPresetNameCalled(this, args);
    return PresetGetPresetNameCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<PresetSetPresetNameResult^>^ PresetServiceEventAdapter::SetPresetNameAsync(_In_ AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberPresetID, _In_ Platform::String^ interfaceMemberPresetName, _In_ Platform::String^ interfaceMemberLanguage)
{
    auto args = ref new PresetSetPresetNameCalledEventArgs(info, interfaceMemberPresetID, interfaceMemberPresetName, interfaceMemberLanguage);
    SetPresetNameCalled(this, args);
    return PresetSetPresetNameCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<PresetCreatePresetResult^>^ PresetServiceEventAdapter::CreatePresetAsync(_In_ AllJoynMessageInfo^ info, _In_ Windows::Foundation::Collections::IMapView<Platform::String^,Platform::Object^>^ interfaceMemberLampState, _In_ Platform::String^ interfaceMemberPresetName, _In_ Platform::String^ interfaceMemberLanguage)
{
    auto args = ref new PresetCreatePresetCalledEventArgs(info, interfaceMemberLampState, interfaceMemberPresetName, interfaceMemberLanguage);
    CreatePresetCalled(this, args);
    return PresetCreatePresetCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<PresetUpdatePresetResult^>^ PresetServiceEventAdapter::UpdatePresetAsync(_In_ AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberPresetID, _In_ Windows::Foundation::Collections::IMapView<Platform::String^,Platform::Object^>^ interfaceMemberLampState)
{
    auto args = ref new PresetUpdatePresetCalledEventArgs(info, interfaceMemberPresetID, interfaceMemberLampState);
    UpdatePresetCalled(this, args);
    return PresetUpdatePresetCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<PresetDeletePresetResult^>^ PresetServiceEventAdapter::DeletePresetAsync(_In_ AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberPresetID)
{
    auto args = ref new PresetDeletePresetCalledEventArgs(info, interfaceMemberPresetID);
    DeletePresetCalled(this, args);
    return PresetDeletePresetCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<PresetGetPresetResult^>^ PresetServiceEventAdapter::GetPresetAsync(_In_ AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberPresetID)
{
    auto args = ref new PresetGetPresetCalledEventArgs(info, interfaceMemberPresetID);
    GetPresetCalled(this, args);
    return PresetGetPresetCalledEventArgs::GetResultAsync(args);
}

// Property Reads
IAsyncOperation<PresetGetVersionResult^>^ PresetServiceEventAdapter::GetVersionAsync(_In_ AllJoynMessageInfo^ info)
{
    auto args = ref new PresetGetVersionRequestedEventArgs(info);
    GetVersionRequested(this, args);
    return PresetGetVersionRequestedEventArgs::GetResultAsync(args);
}

// Property Writes