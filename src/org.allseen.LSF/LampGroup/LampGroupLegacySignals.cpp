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
using namespace org::allseen::LSF::ControllerService::LampGroup;

void LampGroupLegacySignals::Initialize(_In_ alljoyn_busobject busObject, _In_ alljoyn_sessionid sessionId)
{
    m_busObject = busObject;
    m_sessionId = sessionId;

    auto interfaceDefinition = alljoyn_busattachment_getinterface(alljoyn_busobject_getbusattachment(busObject), "org.allseen.LSF.ControllerService.LampGroup");
    alljoyn_interfacedescription_getmember(interfaceDefinition, "LampGroupsNameChanged", &m_memberLampGroupsNameChanged);
    alljoyn_interfacedescription_getmember(interfaceDefinition, "LampGroupsCreated", &m_memberLampGroupsCreated);
    alljoyn_interfacedescription_getmember(interfaceDefinition, "LampGroupsUpdated", &m_memberLampGroupsUpdated);
    alljoyn_interfacedescription_getmember(interfaceDefinition, "LampGroupsDeleted", &m_memberLampGroupsDeleted);
}

void LampGroupLegacySignals::LampGroupsNameChanged(_In_ Windows::Foundation::Collections::IVectorView<Platform::String^>^ interfaceMemberLampGroupsIDs)
{
    if (nullptr == m_busObject)
    {
        return;
    }

    size_t argCount = 1;
    alljoyn_msgarg arguments = alljoyn_msgarg_array_create(argCount);
    (void)TypeConversionHelpers::SetAllJoynMessageArg(alljoyn_msgarg_array_element(arguments, 0), "as", interfaceMemberLampGroupsIDs);
    
    alljoyn_busobject_signal(
        m_busObject, 
        NULL,  // Generated code only supports broadcast signals.
        m_sessionId,
        m_memberLampGroupsNameChanged,
        arguments,
        argCount, 
        0, // A signal with a TTL of 0 will be sent to every member of the session, regardless of how long it takes to deliver the message
        ALLJOYN_MESSAGE_FLAG_GLOBAL_BROADCAST, // Broadcast to everyone in the session.
        NULL); // The generated code does not need the generated signal message

    alljoyn_msgarg_destroy(arguments);
}

void LampGroupLegacySignals::CallLampGroupsNameChangedReceived(_In_ LampGroupLegacySignals^ sender, _In_ LampGroupLampGroupsNameChangedReceivedEventArgs^ args)
{
    LampGroupsNameChangedReceived(sender, args);
}

void LampGroupLegacySignals::LampGroupsCreated(_In_ Windows::Foundation::Collections::IVectorView<Platform::String^>^ interfaceMemberLampGroupsIDs)
{
    if (nullptr == m_busObject)
    {
        return;
    }

    size_t argCount = 1;
    alljoyn_msgarg arguments = alljoyn_msgarg_array_create(argCount);
    (void)TypeConversionHelpers::SetAllJoynMessageArg(alljoyn_msgarg_array_element(arguments, 0), "as", interfaceMemberLampGroupsIDs);
    
    alljoyn_busobject_signal(
        m_busObject, 
        NULL,  // Generated code only supports broadcast signals.
        m_sessionId,
        m_memberLampGroupsCreated,
        arguments,
        argCount, 
        0, // A signal with a TTL of 0 will be sent to every member of the session, regardless of how long it takes to deliver the message
        ALLJOYN_MESSAGE_FLAG_GLOBAL_BROADCAST, // Broadcast to everyone in the session.
        NULL); // The generated code does not need the generated signal message

    alljoyn_msgarg_destroy(arguments);
}

void LampGroupLegacySignals::CallLampGroupsCreatedReceived(_In_ LampGroupLegacySignals^ sender, _In_ LampGroupLampGroupsCreatedReceivedEventArgs^ args)
{
    LampGroupsCreatedReceived(sender, args);
}

void LampGroupLegacySignals::LampGroupsUpdated(_In_ Windows::Foundation::Collections::IVectorView<Platform::String^>^ interfaceMemberLampGroupsIDs)
{
    if (nullptr == m_busObject)
    {
        return;
    }

    size_t argCount = 1;
    alljoyn_msgarg arguments = alljoyn_msgarg_array_create(argCount);
    (void)TypeConversionHelpers::SetAllJoynMessageArg(alljoyn_msgarg_array_element(arguments, 0), "as", interfaceMemberLampGroupsIDs);
    
    alljoyn_busobject_signal(
        m_busObject, 
        NULL,  // Generated code only supports broadcast signals.
        m_sessionId,
        m_memberLampGroupsUpdated,
        arguments,
        argCount, 
        0, // A signal with a TTL of 0 will be sent to every member of the session, regardless of how long it takes to deliver the message
        ALLJOYN_MESSAGE_FLAG_GLOBAL_BROADCAST, // Broadcast to everyone in the session.
        NULL); // The generated code does not need the generated signal message

    alljoyn_msgarg_destroy(arguments);
}

void LampGroupLegacySignals::CallLampGroupsUpdatedReceived(_In_ LampGroupLegacySignals^ sender, _In_ LampGroupLampGroupsUpdatedReceivedEventArgs^ args)
{
    LampGroupsUpdatedReceived(sender, args);
}

void LampGroupLegacySignals::LampGroupsDeleted(_In_ Windows::Foundation::Collections::IVectorView<Platform::String^>^ interfaceMemberLampGroupsIDs)
{
    if (nullptr == m_busObject)
    {
        return;
    }

    size_t argCount = 1;
    alljoyn_msgarg arguments = alljoyn_msgarg_array_create(argCount);
    (void)TypeConversionHelpers::SetAllJoynMessageArg(alljoyn_msgarg_array_element(arguments, 0), "as", interfaceMemberLampGroupsIDs);
    
    alljoyn_busobject_signal(
        m_busObject, 
        NULL,  // Generated code only supports broadcast signals.
        m_sessionId,
        m_memberLampGroupsDeleted,
        arguments,
        argCount, 
        0, // A signal with a TTL of 0 will be sent to every member of the session, regardless of how long it takes to deliver the message
        ALLJOYN_MESSAGE_FLAG_GLOBAL_BROADCAST, // Broadcast to everyone in the session.
        NULL); // The generated code does not need the generated signal message

    alljoyn_msgarg_destroy(arguments);
}

void LampGroupLegacySignals::CallLampGroupsDeletedReceived(_In_ LampGroupLegacySignals^ sender, _In_ LampGroupLampGroupsDeletedReceivedEventArgs^ args)
{
    LampGroupsDeletedReceived(sender, args);
}
