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

using namespace concurrency;

namespace org { namespace allseen { namespace LSF { namespace ControllerService {

ref class ControllerServiceConsumer;

public ref class ControllerServiceLightingResetControllerServiceResult sealed
{
public:
    property int32 Status
    {
        int32 get() { return m_status; }
    internal:
        void set(_In_ int32 value) { m_status = value; }
    }

    property uint32 ResponseCode
    {
        uint32 get() { return m_interfaceMemberResponseCode; }
    internal:
        void set(_In_ uint32 value) { m_interfaceMemberResponseCode = value; }
    }
    
    static ControllerServiceLightingResetControllerServiceResult^ CreateSuccessResult(_In_ uint32 interfaceMemberResponseCode)
    {
        auto result = ref new ControllerServiceLightingResetControllerServiceResult();
        result->Status = Windows::Devices::AllJoyn::AllJoynStatus::Ok;
        result->ResponseCode = interfaceMemberResponseCode;
        result->m_creationContext = Concurrency::task_continuation_context::use_current();
        return result;
    }
    
    static ControllerServiceLightingResetControllerServiceResult^ CreateFailureResult(_In_ int32 status)
    {
        auto result = ref new ControllerServiceLightingResetControllerServiceResult();
        result->Status = status;
        return result;
    }
internal:
    Concurrency::task_continuation_context m_creationContext = Concurrency::task_continuation_context::use_default();

private:
    int32 m_status;
    uint32 m_interfaceMemberResponseCode;
};

public ref class ControllerServiceGetControllerServiceVersionResult sealed
{
public:
    property int32 Status
    {
        int32 get() { return m_status; }
    internal:
        void set(_In_ int32 value) { m_status = value; }
    }

    property uint32 Version
    {
        uint32 get() { return m_interfaceMemberVersion; }
    internal:
        void set(_In_ uint32 value) { m_interfaceMemberVersion = value; }
    }
    
    static ControllerServiceGetControllerServiceVersionResult^ CreateSuccessResult(_In_ uint32 interfaceMemberVersion)
    {
        auto result = ref new ControllerServiceGetControllerServiceVersionResult();
        result->Status = Windows::Devices::AllJoyn::AllJoynStatus::Ok;
        result->Version = interfaceMemberVersion;
        result->m_creationContext = Concurrency::task_continuation_context::use_current();
        return result;
    }
    
    static ControllerServiceGetControllerServiceVersionResult^ CreateFailureResult(_In_ int32 status)
    {
        auto result = ref new ControllerServiceGetControllerServiceVersionResult();
        result->Status = status;
        return result;
    }
internal:
    Concurrency::task_continuation_context m_creationContext = Concurrency::task_continuation_context::use_default();

private:
    int32 m_status;
    uint32 m_interfaceMemberVersion;
};

public ref class ControllerServiceJoinSessionResult sealed
{
public:
    property int32 Status
    {
        int32 get() { return m_status; }
    internal:
        void set(_In_ int32 value) { m_status = value; }
    }

    property ControllerServiceConsumer^ Consumer
    {
        ControllerServiceConsumer^ get() { return m_consumer; }
    internal:
        void set(_In_ ControllerServiceConsumer^ value) { m_consumer = value; }
    };

private:
    int32 m_status;
    ControllerServiceConsumer^ m_consumer;
};

public ref class ControllerServiceGetVersionResult sealed
{
public:
    property int32 Status
    {
        int32 get() { return m_status; }
    internal:
        void set(_In_ int32 value) { m_status = value; }
    }

    property uint32 Version
    {
        uint32 get() { return m_value; }
    internal:
        void set(_In_ uint32 value) { m_value = value; }
    }

    static ControllerServiceGetVersionResult^ CreateSuccessResult(_In_ uint32 value)
    {
        auto result = ref new ControllerServiceGetVersionResult();
        result->Status = Windows::Devices::AllJoyn::AllJoynStatus::Ok;
        result->Version = value;
        result->m_creationContext = Concurrency::task_continuation_context::use_current();
        return result;
    }

    static ControllerServiceGetVersionResult^ CreateFailureResult(_In_ int32 status)
    {
        auto result = ref new ControllerServiceGetVersionResult();
        result->Status = status;
        return result;
    }
internal:
    Concurrency::task_continuation_context m_creationContext = Concurrency::task_continuation_context::use_default();

private:
    int32 m_status;
    uint32 m_value;
};

} } } } 