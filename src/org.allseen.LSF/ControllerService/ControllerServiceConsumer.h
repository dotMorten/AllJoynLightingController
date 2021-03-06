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

namespace org { namespace allseen { namespace LSF { namespace ControllerService {

public interface class IControllerServiceConsumer
{
};

public ref class ControllerServiceConsumer sealed  : [Windows::Foundation::Metadata::Default] IControllerServiceConsumer, org::allseen::LSF::ISignalEmitter
{
public:
    ControllerServiceConsumer(Windows::Devices::AllJoyn::AllJoynBusAttachment^ busAttachment);
    virtual ~ControllerServiceConsumer();

    // Create a consumer from a device Id asynchronously.
    //
    // This is usually called to create a consumer after the unique name of a producer has been reported
    // in the Added callback on the DeviceWatcher.
    static Windows::Foundation::IAsyncOperation<ControllerServiceConsumer^>^ FromIdAsync(_In_ Platform::String^ deviceId);

    // Create a consumer from a device Id asynchronously with the provided bus attachment.
    //
    // This is usually called to create a consumer after the unique name of a producer has been reported
    // in the Added callback on the DeviceWatcher.
    static Windows::Foundation::IAsyncOperation<ControllerServiceConsumer^>^ FromIdAsync(_In_ Platform::String^ deviceId, _In_ Windows::Devices::AllJoyn::AllJoynBusAttachment^ busAttachment);

    int32 ControllerServiceConsumer::Initialize(_In_ Windows::Devices::AllJoyn::AllJoynServiceInfo^ serviceInfo);

    // Call the LightingResetControllerService method
    Windows::Foundation::IAsyncOperation<ControllerServiceLightingResetControllerServiceResult^>^ LightingResetControllerServiceAsync();
    // Call the GetControllerServiceVersion method
    Windows::Foundation::IAsyncOperation<ControllerServiceGetControllerServiceVersionResult^>^ GetControllerServiceVersionAsync();

    // Get the value of the Version property.
    Windows::Foundation::IAsyncOperation<ControllerServiceGetVersionResult^>^ GetVersionAsync();


    // Used to send signals or register functions to handle received signals.
    property ControllerServiceSignals^ Signals
    {
        ControllerServiceSignals^ get() { return m_signals; }
    }

    // Used to get the name of the interface this consumer implements.
    static property Platform::String^ InterfaceName
    { 
        Platform::String^ get() { return AllJoynHelpers::MultibyteToPlatformString(m_interfaceName); }
    }

    virtual property Windows::Devices::AllJoyn::AllJoynBusObject^ BusObject
    { 
        Windows::Devices::AllJoyn::AllJoynBusObject^ get() { return m_busObject; }
    }

    virtual property Windows::Devices::AllJoyn::AllJoynSession^ Session
    { 
        Windows::Devices::AllJoyn::AllJoynSession^ get() { return m_session; }
    }

internal:
    // Consumers do not support property get.
    QStatus OnPropertyGet(_In_ PCSTR interfaceName, _In_ PCSTR propertyName, _Inout_ alljoyn_msgarg val) 
    { 
        UNREFERENCED_PARAMETER(interfaceName); UNREFERENCED_PARAMETER(propertyName); UNREFERENCED_PARAMETER(val); 
        return ER_NOT_IMPLEMENTED; 
    }

    // Consumers do not support property set.
    QStatus OnPropertySet(_In_ PCSTR interfaceName, _In_ PCSTR propertyName, _In_ alljoyn_msgarg val) 
    { 
        UNREFERENCED_PARAMETER(interfaceName); UNREFERENCED_PARAMETER(propertyName); UNREFERENCED_PARAMETER(val);
        return ER_NOT_IMPLEMENTED;
    }

    void OnPropertyChanged(_In_ alljoyn_proxybusobject obj, _In_ PCSTR interfaceName, _In_ const alljoyn_msgarg changed, _In_ const alljoyn_msgarg invalidated);

    property Platform::String^ ServiceObjectPath
    {
        Platform::String^ get() { return m_ServiceObjectPath; }
        void set(Platform::String^ value) { m_ServiceObjectPath = value; }
    }

    property alljoyn_proxybusobject ProxyBusObject
    {
        alljoyn_proxybusobject get() { return m_proxyBusObject; }
        void set(alljoyn_proxybusobject value) { m_proxyBusObject = value; }
    }

private:
    virtual event Windows::Foundation::EventHandler<Platform::Object^>^ _SessionLost;
    virtual event Windows::Foundation::EventHandler<Platform::Object^>^ _SessionMemberAdded;
    virtual event Windows::Foundation::EventHandler<Platform::Object^>^ _SessionMemberRemoved;

    // Register a callback function to handle incoming signals.
    QStatus AddSignalHandler(_In_ alljoyn_busattachment busAttachment, _In_ alljoyn_interfacedescription interfaceDescription, _In_ PCSTR methodName, _In_ alljoyn_messagereceiver_signalhandler_ptr handler);

    static void CallControllerServiceLightingResetSignalHandler(_In_ const alljoyn_interfacedescription_member* member, _In_ alljoyn_message message);
    
    Windows::Devices::AllJoyn::AllJoynBusAttachment^ m_busAttachment;
    Windows::Devices::AllJoyn::AllJoynBusObject^ m_busObject;
    Windows::Devices::AllJoyn::AllJoynSession^ m_session;
    ControllerServiceSignals^ m_signals;
    Platform::String^ m_ServiceObjectPath;

    alljoyn_proxybusobject m_proxyBusObject;
    alljoyn_sessionlistener m_sessionListener;
    alljoyn_busobject m_nativeBusObject;
    alljoyn_busattachment m_nativeBusAttachment;

    // Used to pass a pointer to this class to callbacks
    Platform::WeakReference* m_weak;

    // This map is required because we need a way to pass the consumer to the signal
    // handlers, but the current AllJoyn C API does not allow passing a context to these
    // callbacks.
    static std::map<alljoyn_interfacedescription, Platform::WeakReference*> SourceInterfaces;

    // The name of the interface this consumer implements.
    static PCSTR m_interfaceName;
};

} } } } 
