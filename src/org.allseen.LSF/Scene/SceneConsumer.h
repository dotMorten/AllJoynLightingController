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

public interface class ISceneConsumer
{
};

public ref class SceneConsumer sealed  : [Windows::Foundation::Metadata::Default] ISceneConsumer, org::allseen::LSF::ISignalEmitter
{
public:
    SceneConsumer(Windows::Devices::AllJoyn::AllJoynBusAttachment^ busAttachment);
    virtual ~SceneConsumer();

    // Create a consumer from a device Id asynchronously.
    //
    // This is usually called to create a consumer after the unique name of a producer has been reported
    // in the Added callback on the DeviceWatcher.
    static Windows::Foundation::IAsyncOperation<SceneConsumer^>^ FromIdAsync(_In_ Platform::String^ deviceId);

    // Create a consumer from a device Id asynchronously with the provided bus attachment.
    //
    // This is usually called to create a consumer after the unique name of a producer has been reported
    // in the Added callback on the DeviceWatcher.
    static Windows::Foundation::IAsyncOperation<SceneConsumer^>^ FromIdAsync(_In_ Platform::String^ deviceId, _In_ Windows::Devices::AllJoyn::AllJoynBusAttachment^ busAttachment);

    int32 SceneConsumer::Initialize(_In_ Windows::Devices::AllJoyn::AllJoynServiceInfo^ serviceInfo);

    // Call the GetAllSceneIDs method
    Windows::Foundation::IAsyncOperation<SceneGetAllSceneIDsResult^>^ GetAllSceneIDsAsync();
    // Call the GetSceneName method
    Windows::Foundation::IAsyncOperation<SceneGetSceneNameResult^>^ GetSceneNameAsync(_In_ Platform::String^ interfaceMemberSceneID, _In_ Platform::String^ interfaceMemberLanguage);
    // Call the SetSceneName method
    Windows::Foundation::IAsyncOperation<SceneSetSceneNameResult^>^ SetSceneNameAsync(_In_ Platform::String^ interfaceMemberSceneID, _In_ Platform::String^ interfaceMemberSceneName, _In_ Platform::String^ interfaceMemberLanguage);
    // Call the CreateScene method
    Windows::Foundation::IAsyncOperation<SceneCreateSceneResult^>^ CreateSceneAsync(_In_ Windows::Foundation::Collections::IVectorView<SceneTransitionlampsLampGroupsToStateItem^>^ interfaceMemberTransitionlampsLampGroupsToState, _In_ Windows::Foundation::Collections::IVectorView<SceneTransitionlampsLampGroupsToPresetItem^>^ interfaceMemberTransitionlampsLampGroupsToPreset, _In_ Windows::Foundation::Collections::IVectorView<ScenePulselampsLampGroupsWithStateItem^>^ interfaceMemberPulselampsLampGroupsWithState, _In_ Windows::Foundation::Collections::IVectorView<ScenePulselampsLampGroupsWithPresetItem^>^ interfaceMemberPulselampsLampGroupsWithPreset, _In_ Platform::String^ interfaceMemberSceneName, _In_ Platform::String^ interfaceMemberLanguage);
    // Call the UpdateScene method
    Windows::Foundation::IAsyncOperation<SceneUpdateSceneResult^>^ UpdateSceneAsync(_In_ Platform::String^ interfaceMemberSceneID, _In_ Windows::Foundation::Collections::IVectorView<SceneTransitionlampsLampGroupsToStateItem^>^ interfaceMemberTransitionlampsLampGroupsToState, _In_ Windows::Foundation::Collections::IVectorView<SceneTransitionlampsLampGroupsToPresetItem^>^ interfaceMemberTransitionlampsLampGroupsToPreset, _In_ Windows::Foundation::Collections::IVectorView<ScenePulselampsLampGroupsWithStateItem^>^ interfaceMemberPulselampsLampGroupsWithState, _In_ Windows::Foundation::Collections::IVectorView<ScenePulselampsLampGroupsWithPresetItem^>^ interfaceMemberPulselampsLampGroupsWithPreset);
    // Call the DeleteScene method
    Windows::Foundation::IAsyncOperation<SceneDeleteSceneResult^>^ DeleteSceneAsync(_In_ Platform::String^ interfaceMemberSceneID);
    // Call the GetScene method
    Windows::Foundation::IAsyncOperation<SceneGetSceneResult^>^ GetSceneAsync(_In_ Platform::String^ interfaceMemberSceneID);
    // Call the ApplyScene method
    Windows::Foundation::IAsyncOperation<SceneApplySceneResult^>^ ApplySceneAsync(_In_ Platform::String^ interfaceMemberSceneID);

    // Get the value of the Version property.
    Windows::Foundation::IAsyncOperation<SceneGetVersionResult^>^ GetVersionAsync();


    // Used to send signals or register functions to handle received signals.
    property SceneSignals^ Signals
    {
        SceneSignals^ get() { return m_signals; }
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

    static void CallScenesNameChangedSignalHandler(_In_ const alljoyn_interfacedescription_member* member, _In_ alljoyn_message message);
    static void CallScenesCreatedSignalHandler(_In_ const alljoyn_interfacedescription_member* member, _In_ alljoyn_message message);
    static void CallScenesUpdatedSignalHandler(_In_ const alljoyn_interfacedescription_member* member, _In_ alljoyn_message message);
    static void CallScenesDeletedSignalHandler(_In_ const alljoyn_interfacedescription_member* member, _In_ alljoyn_message message);
    static void CallScenesAppliedSignalHandler(_In_ const alljoyn_interfacedescription_member* member, _In_ alljoyn_message message);

    Windows::Devices::AllJoyn::AllJoynBusAttachment^ m_busAttachment;
    Windows::Devices::AllJoyn::AllJoynBusObject^ m_busObject;
    Windows::Devices::AllJoyn::AllJoynSession^ m_session;
    SceneSignals^ m_signals;
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

} } } } } 
