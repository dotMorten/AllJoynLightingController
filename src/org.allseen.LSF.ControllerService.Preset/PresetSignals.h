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
#pragma once

namespace org { namespace allseen { namespace LSF { namespace ControllerService { namespace Preset {

ref class PresetSignals;

public interface class IPresetSignals
{
    event Windows::Foundation::TypedEventHandler<PresetSignals^, PresetDefaultLampStateChangedReceivedEventArgs^>^ DefaultLampStateChangedReceived;
    event Windows::Foundation::TypedEventHandler<PresetSignals^, PresetPresetsNameChangedReceivedEventArgs^>^ PresetsNameChangedReceived;
    event Windows::Foundation::TypedEventHandler<PresetSignals^, PresetPresetsCreatedReceivedEventArgs^>^ PresetsCreatedReceived;
    event Windows::Foundation::TypedEventHandler<PresetSignals^, PresetPresetsUpdatedReceivedEventArgs^>^ PresetsUpdatedReceived;
    event Windows::Foundation::TypedEventHandler<PresetSignals^, PresetPresetsDeletedReceivedEventArgs^>^ PresetsDeletedReceived;
};

public ref class PresetSignals sealed : [Windows::Foundation::Metadata::Default] IPresetSignals
{
public:
    // Calling this method will send the DefaultLampStateChanged signal to every member of the session.
    void DefaultLampStateChanged();

    // This event fires whenever the DefaultLampStateChanged signal is sent by another member of the session.
    virtual event Windows::Foundation::TypedEventHandler<PresetSignals^, PresetDefaultLampStateChangedReceivedEventArgs^>^ DefaultLampStateChangedReceived 
    { 
        Windows::Foundation::EventRegistrationToken add(Windows::Foundation::TypedEventHandler<PresetSignals^, PresetDefaultLampStateChangedReceivedEventArgs^>^ handler) 
        { 
            return _DefaultLampStateChangedReceived += ref new Windows::Foundation::EventHandler<Platform::Object^>
            ([handler](Platform::Object^ sender, Platform::Object^ args)
            {
                handler->Invoke(safe_cast<PresetSignals^>(sender), safe_cast<PresetDefaultLampStateChangedReceivedEventArgs^>(args));
            }, Platform::CallbackContext::Same);
        } 
        void remove(Windows::Foundation::EventRegistrationToken token) 
        { 
            _DefaultLampStateChangedReceived -= token; 
        } 
    internal: 
        void raise(PresetSignals^ sender, PresetDefaultLampStateChangedReceivedEventArgs^ args) 
        { 
            _DefaultLampStateChangedReceived(sender, args);
        } 
    }

    // Calling this method will send the PresetsNameChanged signal to every member of the session.
    void PresetsNameChanged(_In_ Windows::Foundation::Collections::IVectorView<Platform::String^>^ interfaceMemberPresetIDs);

    // This event fires whenever the PresetsNameChanged signal is sent by another member of the session.
    virtual event Windows::Foundation::TypedEventHandler<PresetSignals^, PresetPresetsNameChangedReceivedEventArgs^>^ PresetsNameChangedReceived 
    { 
        Windows::Foundation::EventRegistrationToken add(Windows::Foundation::TypedEventHandler<PresetSignals^, PresetPresetsNameChangedReceivedEventArgs^>^ handler) 
        { 
            return _PresetsNameChangedReceived += ref new Windows::Foundation::EventHandler<Platform::Object^>
            ([handler](Platform::Object^ sender, Platform::Object^ args)
            {
                handler->Invoke(safe_cast<PresetSignals^>(sender), safe_cast<PresetPresetsNameChangedReceivedEventArgs^>(args));
            }, Platform::CallbackContext::Same);
        } 
        void remove(Windows::Foundation::EventRegistrationToken token) 
        { 
            _PresetsNameChangedReceived -= token; 
        } 
    internal: 
        void raise(PresetSignals^ sender, PresetPresetsNameChangedReceivedEventArgs^ args) 
        { 
            _PresetsNameChangedReceived(sender, args);
        } 
    }

    // Calling this method will send the PresetsCreated signal to every member of the session.
    void PresetsCreated(_In_ Windows::Foundation::Collections::IVectorView<Platform::String^>^ interfaceMemberPresetsIDs);

    // This event fires whenever the PresetsCreated signal is sent by another member of the session.
    virtual event Windows::Foundation::TypedEventHandler<PresetSignals^, PresetPresetsCreatedReceivedEventArgs^>^ PresetsCreatedReceived 
    { 
        Windows::Foundation::EventRegistrationToken add(Windows::Foundation::TypedEventHandler<PresetSignals^, PresetPresetsCreatedReceivedEventArgs^>^ handler) 
        { 
            return _PresetsCreatedReceived += ref new Windows::Foundation::EventHandler<Platform::Object^>
            ([handler](Platform::Object^ sender, Platform::Object^ args)
            {
                handler->Invoke(safe_cast<PresetSignals^>(sender), safe_cast<PresetPresetsCreatedReceivedEventArgs^>(args));
            }, Platform::CallbackContext::Same);
        } 
        void remove(Windows::Foundation::EventRegistrationToken token) 
        { 
            _PresetsCreatedReceived -= token; 
        } 
    internal: 
        void raise(PresetSignals^ sender, PresetPresetsCreatedReceivedEventArgs^ args) 
        { 
            _PresetsCreatedReceived(sender, args);
        } 
    }

    // Calling this method will send the PresetsUpdated signal to every member of the session.
    void PresetsUpdated(_In_ Windows::Foundation::Collections::IVectorView<Platform::String^>^ interfaceMemberPresetsIDs);

    // This event fires whenever the PresetsUpdated signal is sent by another member of the session.
    virtual event Windows::Foundation::TypedEventHandler<PresetSignals^, PresetPresetsUpdatedReceivedEventArgs^>^ PresetsUpdatedReceived 
    { 
        Windows::Foundation::EventRegistrationToken add(Windows::Foundation::TypedEventHandler<PresetSignals^, PresetPresetsUpdatedReceivedEventArgs^>^ handler) 
        { 
            return _PresetsUpdatedReceived += ref new Windows::Foundation::EventHandler<Platform::Object^>
            ([handler](Platform::Object^ sender, Platform::Object^ args)
            {
                handler->Invoke(safe_cast<PresetSignals^>(sender), safe_cast<PresetPresetsUpdatedReceivedEventArgs^>(args));
            }, Platform::CallbackContext::Same);
        } 
        void remove(Windows::Foundation::EventRegistrationToken token) 
        { 
            _PresetsUpdatedReceived -= token; 
        } 
    internal: 
        void raise(PresetSignals^ sender, PresetPresetsUpdatedReceivedEventArgs^ args) 
        { 
            _PresetsUpdatedReceived(sender, args);
        } 
    }

    // Calling this method will send the PresetsDeleted signal to every member of the session.
    void PresetsDeleted(_In_ Windows::Foundation::Collections::IVectorView<Platform::String^>^ interfaceMemberPresetsIDs);

    // This event fires whenever the PresetsDeleted signal is sent by another member of the session.
    virtual event Windows::Foundation::TypedEventHandler<PresetSignals^, PresetPresetsDeletedReceivedEventArgs^>^ PresetsDeletedReceived 
    { 
        Windows::Foundation::EventRegistrationToken add(Windows::Foundation::TypedEventHandler<PresetSignals^, PresetPresetsDeletedReceivedEventArgs^>^ handler) 
        { 
            return _PresetsDeletedReceived += ref new Windows::Foundation::EventHandler<Platform::Object^>
            ([handler](Platform::Object^ sender, Platform::Object^ args)
            {
                handler->Invoke(safe_cast<PresetSignals^>(sender), safe_cast<PresetPresetsDeletedReceivedEventArgs^>(args));
            }, Platform::CallbackContext::Same);
        } 
        void remove(Windows::Foundation::EventRegistrationToken token) 
        { 
            _PresetsDeletedReceived -= token; 
        } 
    internal: 
        void raise(PresetSignals^ sender, PresetPresetsDeletedReceivedEventArgs^ args) 
        { 
            _PresetsDeletedReceived(sender, args);
        } 
    }

internal:
    void Initialize(_In_ alljoyn_busobject busObject, _In_ alljoyn_sessionid sessionId);
    void CallDefaultLampStateChangedReceived(_In_ PresetSignals^ sender, _In_ PresetDefaultLampStateChangedReceivedEventArgs^ args);
    void CallPresetsNameChangedReceived(_In_ PresetSignals^ sender, _In_ PresetPresetsNameChangedReceivedEventArgs^ args);
    void CallPresetsCreatedReceived(_In_ PresetSignals^ sender, _In_ PresetPresetsCreatedReceivedEventArgs^ args);
    void CallPresetsUpdatedReceived(_In_ PresetSignals^ sender, _In_ PresetPresetsUpdatedReceivedEventArgs^ args);
    void CallPresetsDeletedReceived(_In_ PresetSignals^ sender, _In_ PresetPresetsDeletedReceivedEventArgs^ args);

private:
    alljoyn_busobject m_busObject;
    alljoyn_sessionid m_sessionId;

    virtual event Windows::Foundation::EventHandler<Platform::Object^>^ _DefaultLampStateChangedReceived;
    virtual event Windows::Foundation::EventHandler<Platform::Object^>^ _PresetsNameChangedReceived;
    virtual event Windows::Foundation::EventHandler<Platform::Object^>^ _PresetsCreatedReceived;
    virtual event Windows::Foundation::EventHandler<Platform::Object^>^ _PresetsUpdatedReceived;
    virtual event Windows::Foundation::EventHandler<Platform::Object^>^ _PresetsDeletedReceived;

    alljoyn_interfacedescription_member m_memberDefaultLampStateChanged;
    alljoyn_interfacedescription_member m_memberPresetsNameChanged;
    alljoyn_interfacedescription_member m_memberPresetsCreated;
    alljoyn_interfacedescription_member m_memberPresetsUpdated;
    alljoyn_interfacedescription_member m_memberPresetsDeleted;
};

} } } } } 