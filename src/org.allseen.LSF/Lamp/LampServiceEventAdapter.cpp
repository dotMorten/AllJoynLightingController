//-----------------------------------------------------------------------------
// <auto-generated>
//   This code was generated by a tool.
//
//   Changes to this file may cause incorrect behavior and will be lost if
//   the code is regenerated.
//
//   For more information, see: http://go.microsoft.com/fwlink/?LinkID=623246
// </auto-generated>
//-----------------------------------------------------------------------------
#include "pch.h"

using namespace Microsoft::WRL;
using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::Devices::AllJoyn;
using namespace org::allseen::LSF::ControllerService::Lamp;

// Note: Unlike an Interface implementation, which provides a single handler for each member, the event
// model allows for 0 or more listeners to be registered. The EventAdapter implementation deals with this
// difference by implementing a last-writer-wins policy. The lack of any return value (i.e., 0 listeners)
// is handled by returning a null result.

// Methods
IAsyncOperation<LampGetAllLampIDsResult^>^ LampServiceEventAdapter::GetAllLampIDsAsync(_In_ AllJoynMessageInfo^ info)
{
    auto args = ref new LampGetAllLampIDsCalledEventArgs(info);
    GetAllLampIDsCalled(this, args);
    return LampGetAllLampIDsCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<LampGetLampSupportedLanguagesResult^>^ LampServiceEventAdapter::GetLampSupportedLanguagesAsync(_In_ AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampID)
{
    auto args = ref new LampGetLampSupportedLanguagesCalledEventArgs(info, interfaceMemberLampID);
    GetLampSupportedLanguagesCalled(this, args);
    return LampGetLampSupportedLanguagesCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<LampGetLampManufacturerResult^>^ LampServiceEventAdapter::GetLampManufacturerAsync(_In_ AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampID, _In_ Platform::String^ interfaceMemberLanguage)
{
    auto args = ref new LampGetLampManufacturerCalledEventArgs(info, interfaceMemberLampID, interfaceMemberLanguage);
    GetLampManufacturerCalled(this, args);
    return LampGetLampManufacturerCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<LampGetLampNameResult^>^ LampServiceEventAdapter::GetLampNameAsync(_In_ AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampID, _In_ Platform::String^ interfaceMemberLanguage)
{
    auto args = ref new LampGetLampNameCalledEventArgs(info, interfaceMemberLampID, interfaceMemberLanguage);
    GetLampNameCalled(this, args);
    return LampGetLampNameCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<LampSetLampNameResult^>^ LampServiceEventAdapter::SetLampNameAsync(_In_ AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampID, _In_ Platform::String^ interfaceMemberLampName, _In_ Platform::String^ interfaceMemberLanguage)
{
    auto args = ref new LampSetLampNameCalledEventArgs(info, interfaceMemberLampID, interfaceMemberLampName, interfaceMemberLanguage);
    SetLampNameCalled(this, args);
    return LampSetLampNameCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<LampGetLampDetailsResult^>^ LampServiceEventAdapter::GetLampDetailsAsync(_In_ AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampID)
{
    auto args = ref new LampGetLampDetailsCalledEventArgs(info, interfaceMemberLampID);
    GetLampDetailsCalled(this, args);
    return LampGetLampDetailsCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<LampGetLampParametersResult^>^ LampServiceEventAdapter::GetLampParametersAsync(_In_ AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampID)
{
    auto args = ref new LampGetLampParametersCalledEventArgs(info, interfaceMemberLampID);
    GetLampParametersCalled(this, args);
    return LampGetLampParametersCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<LampGetLampParametersFieldResult^>^ LampServiceEventAdapter::GetLampParametersFieldAsync(_In_ AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampID, _In_ Platform::String^ interfaceMemberLampParameterFieldName)
{
    auto args = ref new LampGetLampParametersFieldCalledEventArgs(info, interfaceMemberLampID, interfaceMemberLampParameterFieldName);
    GetLampParametersFieldCalled(this, args);
    return LampGetLampParametersFieldCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<LampGetLampStateResult^>^ LampServiceEventAdapter::GetLampStateAsync(_In_ AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampID)
{
    auto args = ref new LampGetLampStateCalledEventArgs(info, interfaceMemberLampID);
    GetLampStateCalled(this, args);
    return LampGetLampStateCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<LampGetLampStateFieldResult^>^ LampServiceEventAdapter::GetLampStateFieldAsync(_In_ AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampID, _In_ Platform::String^ interfaceMemberLampStateFieldName)
{
    auto args = ref new LampGetLampStateFieldCalledEventArgs(info, interfaceMemberLampID, interfaceMemberLampStateFieldName);
    GetLampStateFieldCalled(this, args);
    return LampGetLampStateFieldCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<LampTransitionLampStateResult^>^ LampServiceEventAdapter::TransitionLampStateAsync(_In_ AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampID, _In_ Windows::Foundation::Collections::IMapView<Platform::String^,Platform::Object^>^ interfaceMemberLampState, _In_ uint32 interfaceMemberTransitionPeriod)
{
    auto args = ref new LampTransitionLampStateCalledEventArgs(info, interfaceMemberLampID, interfaceMemberLampState, interfaceMemberTransitionPeriod);
    TransitionLampStateCalled(this, args);
    return LampTransitionLampStateCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<LampPulseLampWithStateResult^>^ LampServiceEventAdapter::PulseLampWithStateAsync(_In_ AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampID, _In_ Windows::Foundation::Collections::IMapView<Platform::String^,Platform::Object^>^ interfaceMemberFromLampState, _In_ Windows::Foundation::Collections::IMapView<Platform::String^,Platform::Object^>^ interfaceMemberToLampState, _In_ uint32 interfaceMemberPeriod, _In_ uint32 interfaceMemberDuration, _In_ uint32 interfaceMemberNumPulses)
{
    auto args = ref new LampPulseLampWithStateCalledEventArgs(info, interfaceMemberLampID, interfaceMemberFromLampState, interfaceMemberToLampState, interfaceMemberPeriod, interfaceMemberDuration, interfaceMemberNumPulses);
    PulseLampWithStateCalled(this, args);
    return LampPulseLampWithStateCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<LampPulseLampWithPresetResult^>^ LampServiceEventAdapter::PulseLampWithPresetAsync(_In_ AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampID, _In_ Platform::String^ interfaceMemberFromPresetID, _In_ Platform::String^ interfaceMemberToPresetID, _In_ uint32 interfaceMemberPeriod, _In_ uint32 interfaceMemberDuration, _In_ uint32 interfaceMemberNumPulses)
{
    auto args = ref new LampPulseLampWithPresetCalledEventArgs(info, interfaceMemberLampID, interfaceMemberFromPresetID, interfaceMemberToPresetID, interfaceMemberPeriod, interfaceMemberDuration, interfaceMemberNumPulses);
    PulseLampWithPresetCalled(this, args);
    return LampPulseLampWithPresetCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<LampTransitionLampStateToPresetResult^>^ LampServiceEventAdapter::TransitionLampStateToPresetAsync(_In_ AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampID, _In_ Platform::String^ interfaceMemberPresetID, _In_ uint32 interfaceMemberTransitionPeriod)
{
    auto args = ref new LampTransitionLampStateToPresetCalledEventArgs(info, interfaceMemberLampID, interfaceMemberPresetID, interfaceMemberTransitionPeriod);
    TransitionLampStateToPresetCalled(this, args);
    return LampTransitionLampStateToPresetCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<LampTransitionLampStateFieldResult^>^ LampServiceEventAdapter::TransitionLampStateFieldAsync(_In_ AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampID, _In_ Platform::String^ interfaceMemberLampStateFieldName, _In_ Platform::Object^ interfaceMemberLampStateFieldValue, _In_ uint32 interfaceMemberTransitionPeriod)
{
    auto args = ref new LampTransitionLampStateFieldCalledEventArgs(info, interfaceMemberLampID, interfaceMemberLampStateFieldName, interfaceMemberLampStateFieldValue, interfaceMemberTransitionPeriod);
    TransitionLampStateFieldCalled(this, args);
    return LampTransitionLampStateFieldCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<LampResetLampStateResult^>^ LampServiceEventAdapter::ResetLampStateAsync(_In_ AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampID)
{
    auto args = ref new LampResetLampStateCalledEventArgs(info, interfaceMemberLampID);
    ResetLampStateCalled(this, args);
    return LampResetLampStateCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<LampResetLampStateFieldResult^>^ LampServiceEventAdapter::ResetLampStateFieldAsync(_In_ AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampID, _In_ Platform::String^ interfaceMemberLampStateFieldName)
{
    auto args = ref new LampResetLampStateFieldCalledEventArgs(info, interfaceMemberLampID, interfaceMemberLampStateFieldName);
    ResetLampStateFieldCalled(this, args);
    return LampResetLampStateFieldCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<LampGetLampFaultsResult^>^ LampServiceEventAdapter::GetLampFaultsAsync(_In_ AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampID)
{
    auto args = ref new LampGetLampFaultsCalledEventArgs(info, interfaceMemberLampID);
    GetLampFaultsCalled(this, args);
    return LampGetLampFaultsCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<LampClearLampFaultResult^>^ LampServiceEventAdapter::ClearLampFaultAsync(_In_ AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampID, _In_ uint32 interfaceMemberLampFault)
{
    auto args = ref new LampClearLampFaultCalledEventArgs(info, interfaceMemberLampID, interfaceMemberLampFault);
    ClearLampFaultCalled(this, args);
    return LampClearLampFaultCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<LampGetLampServiceVersionResult^>^ LampServiceEventAdapter::GetLampServiceVersionAsync(_In_ AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampID)
{
    auto args = ref new LampGetLampServiceVersionCalledEventArgs(info, interfaceMemberLampID);
    GetLampServiceVersionCalled(this, args);
    return LampGetLampServiceVersionCalledEventArgs::GetResultAsync(args);
}

// Property Reads
IAsyncOperation<LampGetVersionResult^>^ LampServiceEventAdapter::GetVersionAsync(_In_ AllJoynMessageInfo^ info)
{
    auto args = ref new LampGetVersionRequestedEventArgs(info);
    GetVersionRequested(this, args);
    return LampGetVersionRequestedEventArgs::GetResultAsync(args);
}

// Property Writes
