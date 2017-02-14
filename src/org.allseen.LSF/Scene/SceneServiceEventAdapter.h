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

namespace org { namespace allseen { namespace LSF { namespace ControllerService { namespace Scene {

// This class, and the associated EventArgs classes, exist for the benefit of JavaScript developers who
// do not have the ability to implement ISceneService. Instead, SceneServiceEventAdapter
// provides the Interface implementation and exposes a set of compatible events to the developer.
public ref class SceneServiceEventAdapter sealed : [Windows::Foundation::Metadata::Default] ISceneService
{
public:
    // Method Invocation Events
    event Windows::Foundation::TypedEventHandler<SceneServiceEventAdapter^, SceneGetAllSceneIDsCalledEventArgs^>^ GetAllSceneIDsCalled 
    { 
        Windows::Foundation::EventRegistrationToken add(Windows::Foundation::TypedEventHandler<SceneServiceEventAdapter^, SceneGetAllSceneIDsCalledEventArgs^>^ handler) 
        { 
            return _GetAllSceneIDsCalled += ref new Windows::Foundation::EventHandler<Platform::Object^>
            ([handler](Platform::Object^ sender, Platform::Object^ args)
            {
                handler->Invoke(safe_cast<SceneServiceEventAdapter^>(sender), safe_cast<SceneGetAllSceneIDsCalledEventArgs^>(args));
            }, Platform::CallbackContext::Same);
        } 
        void remove(Windows::Foundation::EventRegistrationToken token) 
        { 
            _GetAllSceneIDsCalled -= token; 
        } 
    internal: 
        void raise(SceneServiceEventAdapter^ sender, SceneGetAllSceneIDsCalledEventArgs^ args) 
        { 
            _GetAllSceneIDsCalled(sender, args);
        } 
    }

    event Windows::Foundation::TypedEventHandler<SceneServiceEventAdapter^, SceneGetSceneNameCalledEventArgs^>^ GetSceneNameCalled 
    { 
        Windows::Foundation::EventRegistrationToken add(Windows::Foundation::TypedEventHandler<SceneServiceEventAdapter^, SceneGetSceneNameCalledEventArgs^>^ handler) 
        { 
            return _GetSceneNameCalled += ref new Windows::Foundation::EventHandler<Platform::Object^>
            ([handler](Platform::Object^ sender, Platform::Object^ args)
            {
                handler->Invoke(safe_cast<SceneServiceEventAdapter^>(sender), safe_cast<SceneGetSceneNameCalledEventArgs^>(args));
            }, Platform::CallbackContext::Same);
        } 
        void remove(Windows::Foundation::EventRegistrationToken token) 
        { 
            _GetSceneNameCalled -= token; 
        } 
    internal: 
        void raise(SceneServiceEventAdapter^ sender, SceneGetSceneNameCalledEventArgs^ args) 
        { 
            _GetSceneNameCalled(sender, args);
        } 
    }

    event Windows::Foundation::TypedEventHandler<SceneServiceEventAdapter^, SceneSetSceneNameCalledEventArgs^>^ SetSceneNameCalled 
    { 
        Windows::Foundation::EventRegistrationToken add(Windows::Foundation::TypedEventHandler<SceneServiceEventAdapter^, SceneSetSceneNameCalledEventArgs^>^ handler) 
        { 
            return _SetSceneNameCalled += ref new Windows::Foundation::EventHandler<Platform::Object^>
            ([handler](Platform::Object^ sender, Platform::Object^ args)
            {
                handler->Invoke(safe_cast<SceneServiceEventAdapter^>(sender), safe_cast<SceneSetSceneNameCalledEventArgs^>(args));
            }, Platform::CallbackContext::Same);
        } 
        void remove(Windows::Foundation::EventRegistrationToken token) 
        { 
            _SetSceneNameCalled -= token; 
        } 
    internal: 
        void raise(SceneServiceEventAdapter^ sender, SceneSetSceneNameCalledEventArgs^ args) 
        { 
            _SetSceneNameCalled(sender, args);
        } 
    }

    event Windows::Foundation::TypedEventHandler<SceneServiceEventAdapter^, SceneCreateSceneCalledEventArgs^>^ CreateSceneCalled 
    { 
        Windows::Foundation::EventRegistrationToken add(Windows::Foundation::TypedEventHandler<SceneServiceEventAdapter^, SceneCreateSceneCalledEventArgs^>^ handler) 
        { 
            return _CreateSceneCalled += ref new Windows::Foundation::EventHandler<Platform::Object^>
            ([handler](Platform::Object^ sender, Platform::Object^ args)
            {
                handler->Invoke(safe_cast<SceneServiceEventAdapter^>(sender), safe_cast<SceneCreateSceneCalledEventArgs^>(args));
            }, Platform::CallbackContext::Same);
        } 
        void remove(Windows::Foundation::EventRegistrationToken token) 
        { 
            _CreateSceneCalled -= token; 
        } 
    internal: 
        void raise(SceneServiceEventAdapter^ sender, SceneCreateSceneCalledEventArgs^ args) 
        { 
            _CreateSceneCalled(sender, args);
        } 
    }

    event Windows::Foundation::TypedEventHandler<SceneServiceEventAdapter^, SceneUpdateSceneCalledEventArgs^>^ UpdateSceneCalled 
    { 
        Windows::Foundation::EventRegistrationToken add(Windows::Foundation::TypedEventHandler<SceneServiceEventAdapter^, SceneUpdateSceneCalledEventArgs^>^ handler) 
        { 
            return _UpdateSceneCalled += ref new Windows::Foundation::EventHandler<Platform::Object^>
            ([handler](Platform::Object^ sender, Platform::Object^ args)
            {
                handler->Invoke(safe_cast<SceneServiceEventAdapter^>(sender), safe_cast<SceneUpdateSceneCalledEventArgs^>(args));
            }, Platform::CallbackContext::Same);
        } 
        void remove(Windows::Foundation::EventRegistrationToken token) 
        { 
            _UpdateSceneCalled -= token; 
        } 
    internal: 
        void raise(SceneServiceEventAdapter^ sender, SceneUpdateSceneCalledEventArgs^ args) 
        { 
            _UpdateSceneCalled(sender, args);
        } 
    }

    event Windows::Foundation::TypedEventHandler<SceneServiceEventAdapter^, SceneDeleteSceneCalledEventArgs^>^ DeleteSceneCalled 
    { 
        Windows::Foundation::EventRegistrationToken add(Windows::Foundation::TypedEventHandler<SceneServiceEventAdapter^, SceneDeleteSceneCalledEventArgs^>^ handler) 
        { 
            return _DeleteSceneCalled += ref new Windows::Foundation::EventHandler<Platform::Object^>
            ([handler](Platform::Object^ sender, Platform::Object^ args)
            {
                handler->Invoke(safe_cast<SceneServiceEventAdapter^>(sender), safe_cast<SceneDeleteSceneCalledEventArgs^>(args));
            }, Platform::CallbackContext::Same);
        } 
        void remove(Windows::Foundation::EventRegistrationToken token) 
        { 
            _DeleteSceneCalled -= token; 
        } 
    internal: 
        void raise(SceneServiceEventAdapter^ sender, SceneDeleteSceneCalledEventArgs^ args) 
        { 
            _DeleteSceneCalled(sender, args);
        } 
    }

    event Windows::Foundation::TypedEventHandler<SceneServiceEventAdapter^, SceneGetSceneCalledEventArgs^>^ GetSceneCalled 
    { 
        Windows::Foundation::EventRegistrationToken add(Windows::Foundation::TypedEventHandler<SceneServiceEventAdapter^, SceneGetSceneCalledEventArgs^>^ handler) 
        { 
            return _GetSceneCalled += ref new Windows::Foundation::EventHandler<Platform::Object^>
            ([handler](Platform::Object^ sender, Platform::Object^ args)
            {
                handler->Invoke(safe_cast<SceneServiceEventAdapter^>(sender), safe_cast<SceneGetSceneCalledEventArgs^>(args));
            }, Platform::CallbackContext::Same);
        } 
        void remove(Windows::Foundation::EventRegistrationToken token) 
        { 
            _GetSceneCalled -= token; 
        } 
    internal: 
        void raise(SceneServiceEventAdapter^ sender, SceneGetSceneCalledEventArgs^ args) 
        { 
            _GetSceneCalled(sender, args);
        } 
    }

    event Windows::Foundation::TypedEventHandler<SceneServiceEventAdapter^, SceneApplySceneCalledEventArgs^>^ ApplySceneCalled 
    { 
        Windows::Foundation::EventRegistrationToken add(Windows::Foundation::TypedEventHandler<SceneServiceEventAdapter^, SceneApplySceneCalledEventArgs^>^ handler) 
        { 
            return _ApplySceneCalled += ref new Windows::Foundation::EventHandler<Platform::Object^>
            ([handler](Platform::Object^ sender, Platform::Object^ args)
            {
                handler->Invoke(safe_cast<SceneServiceEventAdapter^>(sender), safe_cast<SceneApplySceneCalledEventArgs^>(args));
            }, Platform::CallbackContext::Same);
        } 
        void remove(Windows::Foundation::EventRegistrationToken token) 
        { 
            _ApplySceneCalled -= token; 
        } 
    internal: 
        void raise(SceneServiceEventAdapter^ sender, SceneApplySceneCalledEventArgs^ args) 
        { 
            _ApplySceneCalled(sender, args);
        } 
    }

    // Property Read Events
    event Windows::Foundation::TypedEventHandler<SceneServiceEventAdapter^, SceneGetVersionRequestedEventArgs^>^ GetVersionRequested 
    { 
        Windows::Foundation::EventRegistrationToken add(Windows::Foundation::TypedEventHandler<SceneServiceEventAdapter^, SceneGetVersionRequestedEventArgs^>^ handler) 
        { 
            return _GetVersionRequested += ref new Windows::Foundation::EventHandler<Platform::Object^>
            ([handler](Platform::Object^ sender, Platform::Object^ args)
            {
                handler->Invoke(safe_cast<SceneServiceEventAdapter^>(sender), safe_cast<SceneGetVersionRequestedEventArgs^>(args));
            }, Platform::CallbackContext::Same);
        } 
        void remove(Windows::Foundation::EventRegistrationToken token) 
        { 
            _GetVersionRequested -= token; 
        } 
    internal: 
        void raise(SceneServiceEventAdapter^ sender, SceneGetVersionRequestedEventArgs^ args) 
        { 
            _GetVersionRequested(sender, args);
        } 
    }

    // Property Write Events
    // ISceneService Implementation
    virtual Windows::Foundation::IAsyncOperation<SceneGetAllSceneIDsResult^>^ GetAllSceneIDsAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info);
    virtual Windows::Foundation::IAsyncOperation<SceneGetSceneNameResult^>^ GetSceneNameAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberSceneID, _In_ Platform::String^ interfaceMemberLanguage);
    virtual Windows::Foundation::IAsyncOperation<SceneSetSceneNameResult^>^ SetSceneNameAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberSceneID, _In_ Platform::String^ interfaceMemberSceneName, _In_ Platform::String^ interfaceMemberLanguage);
    virtual Windows::Foundation::IAsyncOperation<SceneCreateSceneResult^>^ CreateSceneAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Windows::Foundation::Collections::IVectorView<SceneTransitionlampsLampGroupsToStateItem^>^ interfaceMemberTransitionlampsLampGroupsToState, _In_ Windows::Foundation::Collections::IVectorView<SceneTransitionlampsLampGroupsToPresetItem^>^ interfaceMemberTransitionlampsLampGroupsToPreset, _In_ Windows::Foundation::Collections::IVectorView<ScenePulselampsLampGroupsWithStateItem^>^ interfaceMemberPulselampsLampGroupsWithState, _In_ Windows::Foundation::Collections::IVectorView<ScenePulselampsLampGroupsWithPresetItem^>^ interfaceMemberPulselampsLampGroupsWithPreset, _In_ Platform::String^ interfaceMemberSceneName, _In_ Platform::String^ interfaceMemberLanguage);
    virtual Windows::Foundation::IAsyncOperation<SceneUpdateSceneResult^>^ UpdateSceneAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberSceneID, _In_ Windows::Foundation::Collections::IVectorView<SceneTransitionlampsLampGroupsToStateItem^>^ interfaceMemberTransitionlampsLampGroupsToState, _In_ Windows::Foundation::Collections::IVectorView<SceneTransitionlampsLampGroupsToPresetItem^>^ interfaceMemberTransitionlampsLampGroupsToPreset, _In_ Windows::Foundation::Collections::IVectorView<ScenePulselampsLampGroupsWithStateItem^>^ interfaceMemberPulselampsLampGroupsWithState, _In_ Windows::Foundation::Collections::IVectorView<ScenePulselampsLampGroupsWithPresetItem^>^ interfaceMemberPulselampsLampGroupsWithPreset);
    virtual Windows::Foundation::IAsyncOperation<SceneDeleteSceneResult^>^ DeleteSceneAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberSceneID);
    virtual Windows::Foundation::IAsyncOperation<SceneGetSceneResult^>^ GetSceneAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberSceneID);
    virtual Windows::Foundation::IAsyncOperation<SceneApplySceneResult^>^ ApplySceneAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberSceneID);

    virtual Windows::Foundation::IAsyncOperation<SceneGetVersionResult^>^ GetVersionAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info);


private:
    event Windows::Foundation::EventHandler<Platform::Object^>^ _GetAllSceneIDsCalled;
    event Windows::Foundation::EventHandler<Platform::Object^>^ _GetSceneNameCalled;
    event Windows::Foundation::EventHandler<Platform::Object^>^ _SetSceneNameCalled;
    event Windows::Foundation::EventHandler<Platform::Object^>^ _CreateSceneCalled;
    event Windows::Foundation::EventHandler<Platform::Object^>^ _UpdateSceneCalled;
    event Windows::Foundation::EventHandler<Platform::Object^>^ _DeleteSceneCalled;
    event Windows::Foundation::EventHandler<Platform::Object^>^ _GetSceneCalled;
    event Windows::Foundation::EventHandler<Platform::Object^>^ _ApplySceneCalled;
    event Windows::Foundation::EventHandler<Platform::Object^>^ _GetVersionRequested;
};

} } } } } 
