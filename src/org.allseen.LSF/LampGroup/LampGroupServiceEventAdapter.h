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
#pragma once

namespace org { namespace allseen { namespace LSF { namespace ControllerService { namespace LampGroup {

// This class, and the associated EventArgs classes, exist for the benefit of JavaScript developers who
// do not have the ability to implement ILampGroupService. Instead, LampGroupServiceEventAdapter
// provides the Interface implementation and exposes a set of compatible events to the developer.
public ref class LampGroupServiceEventAdapter sealed : [Windows::Foundation::Metadata::Default] ILampGroupService
{
public:
    // Method Invocation Events
    event Windows::Foundation::TypedEventHandler<LampGroupServiceEventAdapter^, LampGroupGetAllLampGroupIDsCalledEventArgs^>^ GetAllLampGroupIDsCalled 
    { 
        Windows::Foundation::EventRegistrationToken add(Windows::Foundation::TypedEventHandler<LampGroupServiceEventAdapter^, LampGroupGetAllLampGroupIDsCalledEventArgs^>^ handler) 
        { 
            return _GetAllLampGroupIDsCalled += ref new Windows::Foundation::EventHandler<Platform::Object^>
            ([handler](Platform::Object^ sender, Platform::Object^ args)
            {
                handler->Invoke(safe_cast<LampGroupServiceEventAdapter^>(sender), safe_cast<LampGroupGetAllLampGroupIDsCalledEventArgs^>(args));
            }, Platform::CallbackContext::Same);
        } 
        void remove(Windows::Foundation::EventRegistrationToken token) 
        { 
            _GetAllLampGroupIDsCalled -= token; 
        } 
    internal: 
        void raise(LampGroupServiceEventAdapter^ sender, LampGroupGetAllLampGroupIDsCalledEventArgs^ args) 
        { 
            _GetAllLampGroupIDsCalled(sender, args);
        } 
    }

    event Windows::Foundation::TypedEventHandler<LampGroupServiceEventAdapter^, LampGroupGetLampGroupNameCalledEventArgs^>^ GetLampGroupNameCalled 
    { 
        Windows::Foundation::EventRegistrationToken add(Windows::Foundation::TypedEventHandler<LampGroupServiceEventAdapter^, LampGroupGetLampGroupNameCalledEventArgs^>^ handler) 
        { 
            return _GetLampGroupNameCalled += ref new Windows::Foundation::EventHandler<Platform::Object^>
            ([handler](Platform::Object^ sender, Platform::Object^ args)
            {
                handler->Invoke(safe_cast<LampGroupServiceEventAdapter^>(sender), safe_cast<LampGroupGetLampGroupNameCalledEventArgs^>(args));
            }, Platform::CallbackContext::Same);
        } 
        void remove(Windows::Foundation::EventRegistrationToken token) 
        { 
            _GetLampGroupNameCalled -= token; 
        } 
    internal: 
        void raise(LampGroupServiceEventAdapter^ sender, LampGroupGetLampGroupNameCalledEventArgs^ args) 
        { 
            _GetLampGroupNameCalled(sender, args);
        } 
    }

    event Windows::Foundation::TypedEventHandler<LampGroupServiceEventAdapter^, LampGroupSetLampGroupNameCalledEventArgs^>^ SetLampGroupNameCalled 
    { 
        Windows::Foundation::EventRegistrationToken add(Windows::Foundation::TypedEventHandler<LampGroupServiceEventAdapter^, LampGroupSetLampGroupNameCalledEventArgs^>^ handler) 
        { 
            return _SetLampGroupNameCalled += ref new Windows::Foundation::EventHandler<Platform::Object^>
            ([handler](Platform::Object^ sender, Platform::Object^ args)
            {
                handler->Invoke(safe_cast<LampGroupServiceEventAdapter^>(sender), safe_cast<LampGroupSetLampGroupNameCalledEventArgs^>(args));
            }, Platform::CallbackContext::Same);
        } 
        void remove(Windows::Foundation::EventRegistrationToken token) 
        { 
            _SetLampGroupNameCalled -= token; 
        } 
    internal: 
        void raise(LampGroupServiceEventAdapter^ sender, LampGroupSetLampGroupNameCalledEventArgs^ args) 
        { 
            _SetLampGroupNameCalled(sender, args);
        } 
    }

    event Windows::Foundation::TypedEventHandler<LampGroupServiceEventAdapter^, LampGroupCreateLampGroupCalledEventArgs^>^ CreateLampGroupCalled 
    { 
        Windows::Foundation::EventRegistrationToken add(Windows::Foundation::TypedEventHandler<LampGroupServiceEventAdapter^, LampGroupCreateLampGroupCalledEventArgs^>^ handler) 
        { 
            return _CreateLampGroupCalled += ref new Windows::Foundation::EventHandler<Platform::Object^>
            ([handler](Platform::Object^ sender, Platform::Object^ args)
            {
                handler->Invoke(safe_cast<LampGroupServiceEventAdapter^>(sender), safe_cast<LampGroupCreateLampGroupCalledEventArgs^>(args));
            }, Platform::CallbackContext::Same);
        } 
        void remove(Windows::Foundation::EventRegistrationToken token) 
        { 
            _CreateLampGroupCalled -= token; 
        } 
    internal: 
        void raise(LampGroupServiceEventAdapter^ sender, LampGroupCreateLampGroupCalledEventArgs^ args) 
        { 
            _CreateLampGroupCalled(sender, args);
        } 
    }

    event Windows::Foundation::TypedEventHandler<LampGroupServiceEventAdapter^, LampGroupUpdateLampGroupCalledEventArgs^>^ UpdateLampGroupCalled 
    { 
        Windows::Foundation::EventRegistrationToken add(Windows::Foundation::TypedEventHandler<LampGroupServiceEventAdapter^, LampGroupUpdateLampGroupCalledEventArgs^>^ handler) 
        { 
            return _UpdateLampGroupCalled += ref new Windows::Foundation::EventHandler<Platform::Object^>
            ([handler](Platform::Object^ sender, Platform::Object^ args)
            {
                handler->Invoke(safe_cast<LampGroupServiceEventAdapter^>(sender), safe_cast<LampGroupUpdateLampGroupCalledEventArgs^>(args));
            }, Platform::CallbackContext::Same);
        } 
        void remove(Windows::Foundation::EventRegistrationToken token) 
        { 
            _UpdateLampGroupCalled -= token; 
        } 
    internal: 
        void raise(LampGroupServiceEventAdapter^ sender, LampGroupUpdateLampGroupCalledEventArgs^ args) 
        { 
            _UpdateLampGroupCalled(sender, args);
        } 
    }

    event Windows::Foundation::TypedEventHandler<LampGroupServiceEventAdapter^, LampGroupDeleteLampGroupCalledEventArgs^>^ DeleteLampGroupCalled 
    { 
        Windows::Foundation::EventRegistrationToken add(Windows::Foundation::TypedEventHandler<LampGroupServiceEventAdapter^, LampGroupDeleteLampGroupCalledEventArgs^>^ handler) 
        { 
            return _DeleteLampGroupCalled += ref new Windows::Foundation::EventHandler<Platform::Object^>
            ([handler](Platform::Object^ sender, Platform::Object^ args)
            {
                handler->Invoke(safe_cast<LampGroupServiceEventAdapter^>(sender), safe_cast<LampGroupDeleteLampGroupCalledEventArgs^>(args));
            }, Platform::CallbackContext::Same);
        } 
        void remove(Windows::Foundation::EventRegistrationToken token) 
        { 
            _DeleteLampGroupCalled -= token; 
        } 
    internal: 
        void raise(LampGroupServiceEventAdapter^ sender, LampGroupDeleteLampGroupCalledEventArgs^ args) 
        { 
            _DeleteLampGroupCalled(sender, args);
        } 
    }

    event Windows::Foundation::TypedEventHandler<LampGroupServiceEventAdapter^, LampGroupGetLampGroupCalledEventArgs^>^ GetLampGroupCalled 
    { 
        Windows::Foundation::EventRegistrationToken add(Windows::Foundation::TypedEventHandler<LampGroupServiceEventAdapter^, LampGroupGetLampGroupCalledEventArgs^>^ handler) 
        { 
            return _GetLampGroupCalled += ref new Windows::Foundation::EventHandler<Platform::Object^>
            ([handler](Platform::Object^ sender, Platform::Object^ args)
            {
                handler->Invoke(safe_cast<LampGroupServiceEventAdapter^>(sender), safe_cast<LampGroupGetLampGroupCalledEventArgs^>(args));
            }, Platform::CallbackContext::Same);
        } 
        void remove(Windows::Foundation::EventRegistrationToken token) 
        { 
            _GetLampGroupCalled -= token; 
        } 
    internal: 
        void raise(LampGroupServiceEventAdapter^ sender, LampGroupGetLampGroupCalledEventArgs^ args) 
        { 
            _GetLampGroupCalled(sender, args);
        } 
    }

    event Windows::Foundation::TypedEventHandler<LampGroupServiceEventAdapter^, LampGroupTransitionLampGroupStateCalledEventArgs^>^ TransitionLampGroupStateCalled 
    { 
        Windows::Foundation::EventRegistrationToken add(Windows::Foundation::TypedEventHandler<LampGroupServiceEventAdapter^, LampGroupTransitionLampGroupStateCalledEventArgs^>^ handler) 
        { 
            return _TransitionLampGroupStateCalled += ref new Windows::Foundation::EventHandler<Platform::Object^>
            ([handler](Platform::Object^ sender, Platform::Object^ args)
            {
                handler->Invoke(safe_cast<LampGroupServiceEventAdapter^>(sender), safe_cast<LampGroupTransitionLampGroupStateCalledEventArgs^>(args));
            }, Platform::CallbackContext::Same);
        } 
        void remove(Windows::Foundation::EventRegistrationToken token) 
        { 
            _TransitionLampGroupStateCalled -= token; 
        } 
    internal: 
        void raise(LampGroupServiceEventAdapter^ sender, LampGroupTransitionLampGroupStateCalledEventArgs^ args) 
        { 
            _TransitionLampGroupStateCalled(sender, args);
        } 
    }

    event Windows::Foundation::TypedEventHandler<LampGroupServiceEventAdapter^, LampGroupPulseLampGroupWithStateCalledEventArgs^>^ PulseLampGroupWithStateCalled 
    { 
        Windows::Foundation::EventRegistrationToken add(Windows::Foundation::TypedEventHandler<LampGroupServiceEventAdapter^, LampGroupPulseLampGroupWithStateCalledEventArgs^>^ handler) 
        { 
            return _PulseLampGroupWithStateCalled += ref new Windows::Foundation::EventHandler<Platform::Object^>
            ([handler](Platform::Object^ sender, Platform::Object^ args)
            {
                handler->Invoke(safe_cast<LampGroupServiceEventAdapter^>(sender), safe_cast<LampGroupPulseLampGroupWithStateCalledEventArgs^>(args));
            }, Platform::CallbackContext::Same);
        } 
        void remove(Windows::Foundation::EventRegistrationToken token) 
        { 
            _PulseLampGroupWithStateCalled -= token; 
        } 
    internal: 
        void raise(LampGroupServiceEventAdapter^ sender, LampGroupPulseLampGroupWithStateCalledEventArgs^ args) 
        { 
            _PulseLampGroupWithStateCalled(sender, args);
        } 
    }

    event Windows::Foundation::TypedEventHandler<LampGroupServiceEventAdapter^, LampGroupPulseLampGroupWithPresetCalledEventArgs^>^ PulseLampGroupWithPresetCalled 
    { 
        Windows::Foundation::EventRegistrationToken add(Windows::Foundation::TypedEventHandler<LampGroupServiceEventAdapter^, LampGroupPulseLampGroupWithPresetCalledEventArgs^>^ handler) 
        { 
            return _PulseLampGroupWithPresetCalled += ref new Windows::Foundation::EventHandler<Platform::Object^>
            ([handler](Platform::Object^ sender, Platform::Object^ args)
            {
                handler->Invoke(safe_cast<LampGroupServiceEventAdapter^>(sender), safe_cast<LampGroupPulseLampGroupWithPresetCalledEventArgs^>(args));
            }, Platform::CallbackContext::Same);
        } 
        void remove(Windows::Foundation::EventRegistrationToken token) 
        { 
            _PulseLampGroupWithPresetCalled -= token; 
        } 
    internal: 
        void raise(LampGroupServiceEventAdapter^ sender, LampGroupPulseLampGroupWithPresetCalledEventArgs^ args) 
        { 
            _PulseLampGroupWithPresetCalled(sender, args);
        } 
    }

    event Windows::Foundation::TypedEventHandler<LampGroupServiceEventAdapter^, LampGroupTransitionLampGroupStateToPresetCalledEventArgs^>^ TransitionLampGroupStateToPresetCalled 
    { 
        Windows::Foundation::EventRegistrationToken add(Windows::Foundation::TypedEventHandler<LampGroupServiceEventAdapter^, LampGroupTransitionLampGroupStateToPresetCalledEventArgs^>^ handler) 
        { 
            return _TransitionLampGroupStateToPresetCalled += ref new Windows::Foundation::EventHandler<Platform::Object^>
            ([handler](Platform::Object^ sender, Platform::Object^ args)
            {
                handler->Invoke(safe_cast<LampGroupServiceEventAdapter^>(sender), safe_cast<LampGroupTransitionLampGroupStateToPresetCalledEventArgs^>(args));
            }, Platform::CallbackContext::Same);
        } 
        void remove(Windows::Foundation::EventRegistrationToken token) 
        { 
            _TransitionLampGroupStateToPresetCalled -= token; 
        } 
    internal: 
        void raise(LampGroupServiceEventAdapter^ sender, LampGroupTransitionLampGroupStateToPresetCalledEventArgs^ args) 
        { 
            _TransitionLampGroupStateToPresetCalled(sender, args);
        } 
    }

    event Windows::Foundation::TypedEventHandler<LampGroupServiceEventAdapter^, LampGroupTransitionLampGroupStateFieldCalledEventArgs^>^ TransitionLampGroupStateFieldCalled 
    { 
        Windows::Foundation::EventRegistrationToken add(Windows::Foundation::TypedEventHandler<LampGroupServiceEventAdapter^, LampGroupTransitionLampGroupStateFieldCalledEventArgs^>^ handler) 
        { 
            return _TransitionLampGroupStateFieldCalled += ref new Windows::Foundation::EventHandler<Platform::Object^>
            ([handler](Platform::Object^ sender, Platform::Object^ args)
            {
                handler->Invoke(safe_cast<LampGroupServiceEventAdapter^>(sender), safe_cast<LampGroupTransitionLampGroupStateFieldCalledEventArgs^>(args));
            }, Platform::CallbackContext::Same);
        } 
        void remove(Windows::Foundation::EventRegistrationToken token) 
        { 
            _TransitionLampGroupStateFieldCalled -= token; 
        } 
    internal: 
        void raise(LampGroupServiceEventAdapter^ sender, LampGroupTransitionLampGroupStateFieldCalledEventArgs^ args) 
        { 
            _TransitionLampGroupStateFieldCalled(sender, args);
        } 
    }

    event Windows::Foundation::TypedEventHandler<LampGroupServiceEventAdapter^, LampGroupResetLampGroupStateCalledEventArgs^>^ ResetLampGroupStateCalled 
    { 
        Windows::Foundation::EventRegistrationToken add(Windows::Foundation::TypedEventHandler<LampGroupServiceEventAdapter^, LampGroupResetLampGroupStateCalledEventArgs^>^ handler) 
        { 
            return _ResetLampGroupStateCalled += ref new Windows::Foundation::EventHandler<Platform::Object^>
            ([handler](Platform::Object^ sender, Platform::Object^ args)
            {
                handler->Invoke(safe_cast<LampGroupServiceEventAdapter^>(sender), safe_cast<LampGroupResetLampGroupStateCalledEventArgs^>(args));
            }, Platform::CallbackContext::Same);
        } 
        void remove(Windows::Foundation::EventRegistrationToken token) 
        { 
            _ResetLampGroupStateCalled -= token; 
        } 
    internal: 
        void raise(LampGroupServiceEventAdapter^ sender, LampGroupResetLampGroupStateCalledEventArgs^ args) 
        { 
            _ResetLampGroupStateCalled(sender, args);
        } 
    }

    event Windows::Foundation::TypedEventHandler<LampGroupServiceEventAdapter^, LampGroupResetLampGroupStateFieldCalledEventArgs^>^ ResetLampGroupStateFieldCalled 
    { 
        Windows::Foundation::EventRegistrationToken add(Windows::Foundation::TypedEventHandler<LampGroupServiceEventAdapter^, LampGroupResetLampGroupStateFieldCalledEventArgs^>^ handler) 
        { 
            return _ResetLampGroupStateFieldCalled += ref new Windows::Foundation::EventHandler<Platform::Object^>
            ([handler](Platform::Object^ sender, Platform::Object^ args)
            {
                handler->Invoke(safe_cast<LampGroupServiceEventAdapter^>(sender), safe_cast<LampGroupResetLampGroupStateFieldCalledEventArgs^>(args));
            }, Platform::CallbackContext::Same);
        } 
        void remove(Windows::Foundation::EventRegistrationToken token) 
        { 
            _ResetLampGroupStateFieldCalled -= token; 
        } 
    internal: 
        void raise(LampGroupServiceEventAdapter^ sender, LampGroupResetLampGroupStateFieldCalledEventArgs^ args) 
        { 
            _ResetLampGroupStateFieldCalled(sender, args);
        } 
    }

    // Property Read Events
    event Windows::Foundation::TypedEventHandler<LampGroupServiceEventAdapter^, LampGroupGetVersionRequestedEventArgs^>^ GetVersionRequested 
    { 
        Windows::Foundation::EventRegistrationToken add(Windows::Foundation::TypedEventHandler<LampGroupServiceEventAdapter^, LampGroupGetVersionRequestedEventArgs^>^ handler) 
        { 
            return _GetVersionRequested += ref new Windows::Foundation::EventHandler<Platform::Object^>
            ([handler](Platform::Object^ sender, Platform::Object^ args)
            {
                handler->Invoke(safe_cast<LampGroupServiceEventAdapter^>(sender), safe_cast<LampGroupGetVersionRequestedEventArgs^>(args));
            }, Platform::CallbackContext::Same);
        } 
        void remove(Windows::Foundation::EventRegistrationToken token) 
        { 
            _GetVersionRequested -= token; 
        } 
    internal: 
        void raise(LampGroupServiceEventAdapter^ sender, LampGroupGetVersionRequestedEventArgs^ args) 
        { 
            _GetVersionRequested(sender, args);
        } 
    }

    // Property Write Events
    // ILampGroupService Implementation
    virtual Windows::Foundation::IAsyncOperation<LampGroupGetAllLampGroupIDsResult^>^ GetAllLampGroupIDsAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info);
    virtual Windows::Foundation::IAsyncOperation<LampGroupGetLampGroupNameResult^>^ GetLampGroupNameAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampGroupID, _In_ Platform::String^ interfaceMemberLanguage);
    virtual Windows::Foundation::IAsyncOperation<LampGroupSetLampGroupNameResult^>^ SetLampGroupNameAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampGroupID, _In_ Platform::String^ interfaceMemberLampGroupName, _In_ Platform::String^ interfaceMemberLanguage);
    virtual Windows::Foundation::IAsyncOperation<LampGroupCreateLampGroupResult^>^ CreateLampGroupAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Windows::Foundation::Collections::IVectorView<Platform::String^>^ interfaceMemberLampIDs, _In_ Windows::Foundation::Collections::IVectorView<Platform::String^>^ interfaceMemberLampGroupIDs, _In_ Platform::String^ interfaceMemberLampGroupName, _In_ Platform::String^ interfaceMemberLanguage);
    virtual Windows::Foundation::IAsyncOperation<LampGroupUpdateLampGroupResult^>^ UpdateLampGroupAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampGroupID, _In_ Windows::Foundation::Collections::IVectorView<Platform::String^>^ interfaceMemberLampIDs, _In_ Windows::Foundation::Collections::IVectorView<Platform::String^>^ interfaceMemberLampGroupIDs);
    virtual Windows::Foundation::IAsyncOperation<LampGroupDeleteLampGroupResult^>^ DeleteLampGroupAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampGroupID);
    virtual Windows::Foundation::IAsyncOperation<LampGroupGetLampGroupResult^>^ GetLampGroupAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampGroupID);
    virtual Windows::Foundation::IAsyncOperation<LampGroupTransitionLampGroupStateResult^>^ TransitionLampGroupStateAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampGroupID, _In_ Windows::Foundation::Collections::IMapView<Platform::String^,Platform::Object^>^ interfaceMemberLampState, _In_ uint32 interfaceMemberTransitionPeriod);
    virtual Windows::Foundation::IAsyncOperation<LampGroupPulseLampGroupWithStateResult^>^ PulseLampGroupWithStateAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampGroupID, _In_ Windows::Foundation::Collections::IMapView<Platform::String^,Platform::Object^>^ interfaceMemberFromLampGroupState, _In_ Windows::Foundation::Collections::IMapView<Platform::String^,Platform::Object^>^ interfaceMemberToLampGroupState, _In_ uint32 interfaceMemberPeriod, _In_ uint32 interfaceMemberDuration, _In_ uint32 interfaceMemberNumPulses);
    virtual Windows::Foundation::IAsyncOperation<LampGroupPulseLampGroupWithPresetResult^>^ PulseLampGroupWithPresetAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampGroupID, _In_ Platform::String^ interfaceMemberFromPresetID, _In_ Platform::String^ interfaceMemberToPresetID, _In_ uint32 interfaceMemberPeriod, _In_ uint32 interfaceMemberDuration, _In_ uint32 interfaceMemberNumPulses);
    virtual Windows::Foundation::IAsyncOperation<LampGroupTransitionLampGroupStateToPresetResult^>^ TransitionLampGroupStateToPresetAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampGroupID, _In_ Platform::String^ interfaceMemberPresetID, _In_ uint32 interfaceMemberTransitionPeriod);
    virtual Windows::Foundation::IAsyncOperation<LampGroupTransitionLampGroupStateFieldResult^>^ TransitionLampGroupStateFieldAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampGroupID, _In_ Platform::String^ interfaceMemberLampGroupStateFieldName, _In_ Platform::Object^ interfaceMemberLampGroupStateFieldValue, _In_ uint32 interfaceMemberTransitionPeriod);
    virtual Windows::Foundation::IAsyncOperation<LampGroupResetLampGroupStateResult^>^ ResetLampGroupStateAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampGroupID);
    virtual Windows::Foundation::IAsyncOperation<LampGroupResetLampGroupStateFieldResult^>^ ResetLampGroupStateFieldAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampGroupID, _In_ Platform::String^ interfaceMemberLampGroupStateFieldName);

    virtual Windows::Foundation::IAsyncOperation<LampGroupGetVersionResult^>^ GetVersionAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info);


private:
    event Windows::Foundation::EventHandler<Platform::Object^>^ _GetAllLampGroupIDsCalled;
    event Windows::Foundation::EventHandler<Platform::Object^>^ _GetLampGroupNameCalled;
    event Windows::Foundation::EventHandler<Platform::Object^>^ _SetLampGroupNameCalled;
    event Windows::Foundation::EventHandler<Platform::Object^>^ _CreateLampGroupCalled;
    event Windows::Foundation::EventHandler<Platform::Object^>^ _UpdateLampGroupCalled;
    event Windows::Foundation::EventHandler<Platform::Object^>^ _DeleteLampGroupCalled;
    event Windows::Foundation::EventHandler<Platform::Object^>^ _GetLampGroupCalled;
    event Windows::Foundation::EventHandler<Platform::Object^>^ _TransitionLampGroupStateCalled;
    event Windows::Foundation::EventHandler<Platform::Object^>^ _PulseLampGroupWithStateCalled;
    event Windows::Foundation::EventHandler<Platform::Object^>^ _PulseLampGroupWithPresetCalled;
    event Windows::Foundation::EventHandler<Platform::Object^>^ _TransitionLampGroupStateToPresetCalled;
    event Windows::Foundation::EventHandler<Platform::Object^>^ _TransitionLampGroupStateFieldCalled;
    event Windows::Foundation::EventHandler<Platform::Object^>^ _ResetLampGroupStateCalled;
    event Windows::Foundation::EventHandler<Platform::Object^>^ _ResetLampGroupStateFieldCalled;
    event Windows::Foundation::EventHandler<Platform::Object^>^ _GetVersionRequested;
};

} } } } } 
