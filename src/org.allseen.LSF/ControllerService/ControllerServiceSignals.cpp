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
using namespace Windows::Devices::AllJoyn;
using namespace Windows::Foundation;
using namespace org::allseen::LSF::ControllerService;

void ControllerServiceSignals::Initialize(_In_ org::allseen::LSF::ISignalEmitter^ emitter)
{
    m_emitter = emitter;
    alljoyn_busattachment nativeBusAttachment = AllJoynHelpers::GetInternalBusAttachment(m_emitter->BusObject->BusAttachment);
    auto interfaceDefinition = alljoyn_busattachment_getinterface(nativeBusAttachment, "org.allseen.LSF.ControllerService");
    alljoyn_interfacedescription_getmember(interfaceDefinition, "ControllerServiceLightingReset", &m_memberControllerServiceLightingReset);
}

void ControllerServiceSignals::ControllerServiceLightingReset()
{
    if (nullptr == AllJoynHelpers::GetInternalBusObject(m_emitter->BusObject))
    {
        return;
    }

    size_t argCount = 0;
    alljoyn_msgarg arguments = alljoyn_msgarg_array_create(argCount);
    
    alljoyn_busobject_signal(
        AllJoynHelpers::GetInternalBusObject(m_emitter->BusObject), 
        NULL,  // Generated code only supports broadcast signals.
        m_emitter->Session->Id,
        m_memberControllerServiceLightingReset,
        arguments,
        argCount, 
        0, // A signal with a TTL of 0 will be sent to every member of the session, regardless of how long it takes to deliver the message
        ALLJOYN_MESSAGE_FLAG_GLOBAL_BROADCAST, // Broadcast to everyone in the session.
        NULL); // The generated code does not need the generated signal message

    alljoyn_msgarg_destroy(arguments);
}

void ControllerServiceSignals::CallControllerServiceLightingResetReceived(_In_ ControllerServiceSignals^ sender, _In_ ControllerServiceControllerServiceLightingResetReceivedEventArgs^ args)
{
    ControllerServiceLightingResetReceived(sender, args);
}

