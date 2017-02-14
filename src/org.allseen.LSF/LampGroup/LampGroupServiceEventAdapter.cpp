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
using namespace org::allseen::LSF::ControllerService::LampGroup;

// Note: Unlike an Interface implementation, which provides a single handler for each member, the event
// model allows for 0 or more listeners to be registered. The EventAdapter implementation deals with this
// difference by implementing a last-writer-wins policy. The lack of any return value (i.e., 0 listeners)
// is handled by returning a null result.

// Methods
IAsyncOperation<LampGroupGetAllLampGroupIDsResult^>^ LampGroupServiceEventAdapter::GetAllLampGroupIDsAsync(_In_ AllJoynMessageInfo^ info)
{
    auto args = ref new LampGroupGetAllLampGroupIDsCalledEventArgs(info);
    GetAllLampGroupIDsCalled(this, args);
    return LampGroupGetAllLampGroupIDsCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<LampGroupGetLampGroupNameResult^>^ LampGroupServiceEventAdapter::GetLampGroupNameAsync(_In_ AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampGroupID, _In_ Platform::String^ interfaceMemberLanguage)
{
    auto args = ref new LampGroupGetLampGroupNameCalledEventArgs(info, interfaceMemberLampGroupID, interfaceMemberLanguage);
    GetLampGroupNameCalled(this, args);
    return LampGroupGetLampGroupNameCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<LampGroupSetLampGroupNameResult^>^ LampGroupServiceEventAdapter::SetLampGroupNameAsync(_In_ AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampGroupID, _In_ Platform::String^ interfaceMemberLampGroupName, _In_ Platform::String^ interfaceMemberLanguage)
{
    auto args = ref new LampGroupSetLampGroupNameCalledEventArgs(info, interfaceMemberLampGroupID, interfaceMemberLampGroupName, interfaceMemberLanguage);
    SetLampGroupNameCalled(this, args);
    return LampGroupSetLampGroupNameCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<LampGroupCreateLampGroupResult^>^ LampGroupServiceEventAdapter::CreateLampGroupAsync(_In_ AllJoynMessageInfo^ info, _In_ Windows::Foundation::Collections::IVectorView<Platform::String^>^ interfaceMemberLampIDs, _In_ Windows::Foundation::Collections::IVectorView<Platform::String^>^ interfaceMemberLampGroupIDs, _In_ Platform::String^ interfaceMemberLampGroupName, _In_ Platform::String^ interfaceMemberLanguage)
{
    auto args = ref new LampGroupCreateLampGroupCalledEventArgs(info, interfaceMemberLampIDs, interfaceMemberLampGroupIDs, interfaceMemberLampGroupName, interfaceMemberLanguage);
    CreateLampGroupCalled(this, args);
    return LampGroupCreateLampGroupCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<LampGroupUpdateLampGroupResult^>^ LampGroupServiceEventAdapter::UpdateLampGroupAsync(_In_ AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampGroupID, _In_ Windows::Foundation::Collections::IVectorView<Platform::String^>^ interfaceMemberLampIDs, _In_ Windows::Foundation::Collections::IVectorView<Platform::String^>^ interfaceMemberLampGroupIDs)
{
    auto args = ref new LampGroupUpdateLampGroupCalledEventArgs(info, interfaceMemberLampGroupID, interfaceMemberLampIDs, interfaceMemberLampGroupIDs);
    UpdateLampGroupCalled(this, args);
    return LampGroupUpdateLampGroupCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<LampGroupDeleteLampGroupResult^>^ LampGroupServiceEventAdapter::DeleteLampGroupAsync(_In_ AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampGroupID)
{
    auto args = ref new LampGroupDeleteLampGroupCalledEventArgs(info, interfaceMemberLampGroupID);
    DeleteLampGroupCalled(this, args);
    return LampGroupDeleteLampGroupCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<LampGroupGetLampGroupResult^>^ LampGroupServiceEventAdapter::GetLampGroupAsync(_In_ AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampGroupID)
{
    auto args = ref new LampGroupGetLampGroupCalledEventArgs(info, interfaceMemberLampGroupID);
    GetLampGroupCalled(this, args);
    return LampGroupGetLampGroupCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<LampGroupTransitionLampGroupStateResult^>^ LampGroupServiceEventAdapter::TransitionLampGroupStateAsync(_In_ AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampGroupID, _In_ Windows::Foundation::Collections::IMapView<Platform::String^,Platform::Object^>^ interfaceMemberLampState, _In_ uint32 interfaceMemberTransitionPeriod)
{
    auto args = ref new LampGroupTransitionLampGroupStateCalledEventArgs(info, interfaceMemberLampGroupID, interfaceMemberLampState, interfaceMemberTransitionPeriod);
    TransitionLampGroupStateCalled(this, args);
    return LampGroupTransitionLampGroupStateCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<LampGroupPulseLampGroupWithStateResult^>^ LampGroupServiceEventAdapter::PulseLampGroupWithStateAsync(_In_ AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampGroupID, _In_ Windows::Foundation::Collections::IMapView<Platform::String^,Platform::Object^>^ interfaceMemberFromLampGroupState, _In_ Windows::Foundation::Collections::IMapView<Platform::String^,Platform::Object^>^ interfaceMemberToLampGroupState, _In_ uint32 interfaceMemberPeriod, _In_ uint32 interfaceMemberDuration, _In_ uint32 interfaceMemberNumPulses)
{
    auto args = ref new LampGroupPulseLampGroupWithStateCalledEventArgs(info, interfaceMemberLampGroupID, interfaceMemberFromLampGroupState, interfaceMemberToLampGroupState, interfaceMemberPeriod, interfaceMemberDuration, interfaceMemberNumPulses);
    PulseLampGroupWithStateCalled(this, args);
    return LampGroupPulseLampGroupWithStateCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<LampGroupPulseLampGroupWithPresetResult^>^ LampGroupServiceEventAdapter::PulseLampGroupWithPresetAsync(_In_ AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampGroupID, _In_ Platform::String^ interfaceMemberFromPresetID, _In_ Platform::String^ interfaceMemberToPresetID, _In_ uint32 interfaceMemberPeriod, _In_ uint32 interfaceMemberDuration, _In_ uint32 interfaceMemberNumPulses)
{
    auto args = ref new LampGroupPulseLampGroupWithPresetCalledEventArgs(info, interfaceMemberLampGroupID, interfaceMemberFromPresetID, interfaceMemberToPresetID, interfaceMemberPeriod, interfaceMemberDuration, interfaceMemberNumPulses);
    PulseLampGroupWithPresetCalled(this, args);
    return LampGroupPulseLampGroupWithPresetCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<LampGroupTransitionLampGroupStateToPresetResult^>^ LampGroupServiceEventAdapter::TransitionLampGroupStateToPresetAsync(_In_ AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampGroupID, _In_ Platform::String^ interfaceMemberPresetID, _In_ uint32 interfaceMemberTransitionPeriod)
{
    auto args = ref new LampGroupTransitionLampGroupStateToPresetCalledEventArgs(info, interfaceMemberLampGroupID, interfaceMemberPresetID, interfaceMemberTransitionPeriod);
    TransitionLampGroupStateToPresetCalled(this, args);
    return LampGroupTransitionLampGroupStateToPresetCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<LampGroupTransitionLampGroupStateFieldResult^>^ LampGroupServiceEventAdapter::TransitionLampGroupStateFieldAsync(_In_ AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampGroupID, _In_ Platform::String^ interfaceMemberLampGroupStateFieldName, _In_ Platform::Object^ interfaceMemberLampGroupStateFieldValue, _In_ uint32 interfaceMemberTransitionPeriod)
{
    auto args = ref new LampGroupTransitionLampGroupStateFieldCalledEventArgs(info, interfaceMemberLampGroupID, interfaceMemberLampGroupStateFieldName, interfaceMemberLampGroupStateFieldValue, interfaceMemberTransitionPeriod);
    TransitionLampGroupStateFieldCalled(this, args);
    return LampGroupTransitionLampGroupStateFieldCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<LampGroupResetLampGroupStateResult^>^ LampGroupServiceEventAdapter::ResetLampGroupStateAsync(_In_ AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampGroupID)
{
    auto args = ref new LampGroupResetLampGroupStateCalledEventArgs(info, interfaceMemberLampGroupID);
    ResetLampGroupStateCalled(this, args);
    return LampGroupResetLampGroupStateCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<LampGroupResetLampGroupStateFieldResult^>^ LampGroupServiceEventAdapter::ResetLampGroupStateFieldAsync(_In_ AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampGroupID, _In_ Platform::String^ interfaceMemberLampGroupStateFieldName)
{
    auto args = ref new LampGroupResetLampGroupStateFieldCalledEventArgs(info, interfaceMemberLampGroupID, interfaceMemberLampGroupStateFieldName);
    ResetLampGroupStateFieldCalled(this, args);
    return LampGroupResetLampGroupStateFieldCalledEventArgs::GetResultAsync(args);
}

// Property Reads
IAsyncOperation<LampGroupGetVersionResult^>^ LampGroupServiceEventAdapter::GetVersionAsync(_In_ AllJoynMessageInfo^ info)
{
    auto args = ref new LampGroupGetVersionRequestedEventArgs(info);
    GetVersionRequested(this, args);
    return LampGroupGetVersionRequestedEventArgs::GetResultAsync(args);
}

// Property Writes
