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

namespace org { namespace allseen { namespace LSF { namespace ControllerService { namespace Preset {

ref class PresetConsumer;

public ref class PresetGetDefaultLampStateResult sealed
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
    property Windows::Foundation::Collections::IMap<Platform::String^,Platform::Object^>^ LampState
    {
        Windows::Foundation::Collections::IMap<Platform::String^,Platform::Object^>^ get() { return m_interfaceMemberLampState; }
    internal:
        void set(_In_ Windows::Foundation::Collections::IMap<Platform::String^,Platform::Object^>^ value) { m_interfaceMemberLampState = value; }
    }
    
    static PresetGetDefaultLampStateResult^ CreateSuccessResult(_In_ uint32 interfaceMemberResponseCode, _In_ Windows::Foundation::Collections::IMap<Platform::String^,Platform::Object^>^ interfaceMemberLampState)
    {
        auto result = ref new PresetGetDefaultLampStateResult();
        result->Status = Windows::Devices::AllJoyn::AllJoynStatus::Ok;
        result->ResponseCode = interfaceMemberResponseCode;
        result->LampState = interfaceMemberLampState;
        result->m_creationContext = Concurrency::task_continuation_context::use_current();
        return result;
    }
    
    static PresetGetDefaultLampStateResult^ CreateFailureResult(_In_ int32 status)
    {
        auto result = ref new PresetGetDefaultLampStateResult();
        result->Status = status;
        return result;
    }
internal:
    Concurrency::task_continuation_context m_creationContext = Concurrency::task_continuation_context::use_default();

private:
    int32 m_status;
    uint32 m_interfaceMemberResponseCode;
    Windows::Foundation::Collections::IMap<Platform::String^,Platform::Object^>^ m_interfaceMemberLampState;
};

public ref class PresetSetDefaultLampStateResult sealed
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
    
    static PresetSetDefaultLampStateResult^ CreateSuccessResult(_In_ uint32 interfaceMemberResponseCode)
    {
        auto result = ref new PresetSetDefaultLampStateResult();
        result->Status = Windows::Devices::AllJoyn::AllJoynStatus::Ok;
        result->ResponseCode = interfaceMemberResponseCode;
        result->m_creationContext = Concurrency::task_continuation_context::use_current();
        return result;
    }
    
    static PresetSetDefaultLampStateResult^ CreateFailureResult(_In_ int32 status)
    {
        auto result = ref new PresetSetDefaultLampStateResult();
        result->Status = status;
        return result;
    }
internal:
    Concurrency::task_continuation_context m_creationContext = Concurrency::task_continuation_context::use_default();

private:
    int32 m_status;
    uint32 m_interfaceMemberResponseCode;
};

public ref class PresetGetAllPresetIDsResult sealed
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
    property Windows::Foundation::Collections::IVector<Platform::String^>^ PresetIDs
    {
        Windows::Foundation::Collections::IVector<Platform::String^>^ get() { return m_interfaceMemberPresetIDs; }
    internal:
        void set(_In_ Windows::Foundation::Collections::IVector<Platform::String^>^ value) { m_interfaceMemberPresetIDs = value; }
    }
    
    static PresetGetAllPresetIDsResult^ CreateSuccessResult(_In_ uint32 interfaceMemberResponseCode, _In_ Windows::Foundation::Collections::IVector<Platform::String^>^ interfaceMemberPresetIDs)
    {
        auto result = ref new PresetGetAllPresetIDsResult();
        result->Status = Windows::Devices::AllJoyn::AllJoynStatus::Ok;
        result->ResponseCode = interfaceMemberResponseCode;
        result->PresetIDs = interfaceMemberPresetIDs;
        result->m_creationContext = Concurrency::task_continuation_context::use_current();
        return result;
    }
    
    static PresetGetAllPresetIDsResult^ CreateFailureResult(_In_ int32 status)
    {
        auto result = ref new PresetGetAllPresetIDsResult();
        result->Status = status;
        return result;
    }
internal:
    Concurrency::task_continuation_context m_creationContext = Concurrency::task_continuation_context::use_default();

private:
    int32 m_status;
    uint32 m_interfaceMemberResponseCode;
    Windows::Foundation::Collections::IVector<Platform::String^>^ m_interfaceMemberPresetIDs;
};

public ref class PresetGetPresetNameResult sealed
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
    property Platform::String^ PresetID
    {
        Platform::String^ get() { return m_interfaceMemberPresetID; }
    internal:
        void set(_In_ Platform::String^ value) { m_interfaceMemberPresetID = value; }
    }
    property Platform::String^ Language
    {
        Platform::String^ get() { return m_interfaceMemberLanguage; }
    internal:
        void set(_In_ Platform::String^ value) { m_interfaceMemberLanguage = value; }
    }
    property Platform::String^ PresetName
    {
        Platform::String^ get() { return m_interfaceMemberPresetName; }
    internal:
        void set(_In_ Platform::String^ value) { m_interfaceMemberPresetName = value; }
    }
    
    static PresetGetPresetNameResult^ CreateSuccessResult(_In_ uint32 interfaceMemberResponseCode, _In_ Platform::String^ interfaceMemberPresetID, _In_ Platform::String^ interfaceMemberLanguage, _In_ Platform::String^ interfaceMemberPresetName)
    {
        auto result = ref new PresetGetPresetNameResult();
        result->Status = Windows::Devices::AllJoyn::AllJoynStatus::Ok;
        result->ResponseCode = interfaceMemberResponseCode;
        result->PresetID = interfaceMemberPresetID;
        result->Language = interfaceMemberLanguage;
        result->PresetName = interfaceMemberPresetName;
        result->m_creationContext = Concurrency::task_continuation_context::use_current();
        return result;
    }
    
    static PresetGetPresetNameResult^ CreateFailureResult(_In_ int32 status)
    {
        auto result = ref new PresetGetPresetNameResult();
        result->Status = status;
        return result;
    }
internal:
    Concurrency::task_continuation_context m_creationContext = Concurrency::task_continuation_context::use_default();

private:
    int32 m_status;
    uint32 m_interfaceMemberResponseCode;
    Platform::String^ m_interfaceMemberPresetID;
    Platform::String^ m_interfaceMemberLanguage;
    Platform::String^ m_interfaceMemberPresetName;
};

public ref class PresetSetPresetNameResult sealed
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
    property Platform::String^ PresetID
    {
        Platform::String^ get() { return m_interfaceMemberPresetID; }
    internal:
        void set(_In_ Platform::String^ value) { m_interfaceMemberPresetID = value; }
    }
    property Platform::String^ Language
    {
        Platform::String^ get() { return m_interfaceMemberLanguage; }
    internal:
        void set(_In_ Platform::String^ value) { m_interfaceMemberLanguage = value; }
    }
    
    static PresetSetPresetNameResult^ CreateSuccessResult(_In_ uint32 interfaceMemberResponseCode, _In_ Platform::String^ interfaceMemberPresetID, _In_ Platform::String^ interfaceMemberLanguage)
    {
        auto result = ref new PresetSetPresetNameResult();
        result->Status = Windows::Devices::AllJoyn::AllJoynStatus::Ok;
        result->ResponseCode = interfaceMemberResponseCode;
        result->PresetID = interfaceMemberPresetID;
        result->Language = interfaceMemberLanguage;
        result->m_creationContext = Concurrency::task_continuation_context::use_current();
        return result;
    }
    
    static PresetSetPresetNameResult^ CreateFailureResult(_In_ int32 status)
    {
        auto result = ref new PresetSetPresetNameResult();
        result->Status = status;
        return result;
    }
internal:
    Concurrency::task_continuation_context m_creationContext = Concurrency::task_continuation_context::use_default();

private:
    int32 m_status;
    uint32 m_interfaceMemberResponseCode;
    Platform::String^ m_interfaceMemberPresetID;
    Platform::String^ m_interfaceMemberLanguage;
};

public ref class PresetCreatePresetResult sealed
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
    property Platform::String^ PresetID
    {
        Platform::String^ get() { return m_interfaceMemberPresetID; }
    internal:
        void set(_In_ Platform::String^ value) { m_interfaceMemberPresetID = value; }
    }
    
    static PresetCreatePresetResult^ CreateSuccessResult(_In_ uint32 interfaceMemberResponseCode, _In_ Platform::String^ interfaceMemberPresetID)
    {
        auto result = ref new PresetCreatePresetResult();
        result->Status = Windows::Devices::AllJoyn::AllJoynStatus::Ok;
        result->ResponseCode = interfaceMemberResponseCode;
        result->PresetID = interfaceMemberPresetID;
        result->m_creationContext = Concurrency::task_continuation_context::use_current();
        return result;
    }
    
    static PresetCreatePresetResult^ CreateFailureResult(_In_ int32 status)
    {
        auto result = ref new PresetCreatePresetResult();
        result->Status = status;
        return result;
    }
internal:
    Concurrency::task_continuation_context m_creationContext = Concurrency::task_continuation_context::use_default();

private:
    int32 m_status;
    uint32 m_interfaceMemberResponseCode;
    Platform::String^ m_interfaceMemberPresetID;
};

public ref class PresetUpdatePresetResult sealed
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
    property Platform::String^ PresetID
    {
        Platform::String^ get() { return m_interfaceMemberPresetID; }
    internal:
        void set(_In_ Platform::String^ value) { m_interfaceMemberPresetID = value; }
    }
    
    static PresetUpdatePresetResult^ CreateSuccessResult(_In_ uint32 interfaceMemberResponseCode, _In_ Platform::String^ interfaceMemberPresetID)
    {
        auto result = ref new PresetUpdatePresetResult();
        result->Status = Windows::Devices::AllJoyn::AllJoynStatus::Ok;
        result->ResponseCode = interfaceMemberResponseCode;
        result->PresetID = interfaceMemberPresetID;
        result->m_creationContext = Concurrency::task_continuation_context::use_current();
        return result;
    }
    
    static PresetUpdatePresetResult^ CreateFailureResult(_In_ int32 status)
    {
        auto result = ref new PresetUpdatePresetResult();
        result->Status = status;
        return result;
    }
internal:
    Concurrency::task_continuation_context m_creationContext = Concurrency::task_continuation_context::use_default();

private:
    int32 m_status;
    uint32 m_interfaceMemberResponseCode;
    Platform::String^ m_interfaceMemberPresetID;
};

public ref class PresetDeletePresetResult sealed
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
    property Platform::String^ PresetID
    {
        Platform::String^ get() { return m_interfaceMemberPresetID; }
    internal:
        void set(_In_ Platform::String^ value) { m_interfaceMemberPresetID = value; }
    }
    
    static PresetDeletePresetResult^ CreateSuccessResult(_In_ uint32 interfaceMemberResponseCode, _In_ Platform::String^ interfaceMemberPresetID)
    {
        auto result = ref new PresetDeletePresetResult();
        result->Status = Windows::Devices::AllJoyn::AllJoynStatus::Ok;
        result->ResponseCode = interfaceMemberResponseCode;
        result->PresetID = interfaceMemberPresetID;
        result->m_creationContext = Concurrency::task_continuation_context::use_current();
        return result;
    }
    
    static PresetDeletePresetResult^ CreateFailureResult(_In_ int32 status)
    {
        auto result = ref new PresetDeletePresetResult();
        result->Status = status;
        return result;
    }
internal:
    Concurrency::task_continuation_context m_creationContext = Concurrency::task_continuation_context::use_default();

private:
    int32 m_status;
    uint32 m_interfaceMemberResponseCode;
    Platform::String^ m_interfaceMemberPresetID;
};

public ref class PresetGetPresetResult sealed
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
    property Platform::String^ PresetID
    {
        Platform::String^ get() { return m_interfaceMemberPresetID; }
    internal:
        void set(_In_ Platform::String^ value) { m_interfaceMemberPresetID = value; }
    }
    property Windows::Foundation::Collections::IMap<Platform::String^,Platform::Object^>^ LampState
    {
        Windows::Foundation::Collections::IMap<Platform::String^,Platform::Object^>^ get() { return m_interfaceMemberLampState; }
    internal:
        void set(_In_ Windows::Foundation::Collections::IMap<Platform::String^,Platform::Object^>^ value) { m_interfaceMemberLampState = value; }
    }
    
    static PresetGetPresetResult^ CreateSuccessResult(_In_ uint32 interfaceMemberResponseCode, _In_ Platform::String^ interfaceMemberPresetID, _In_ Windows::Foundation::Collections::IMap<Platform::String^,Platform::Object^>^ interfaceMemberLampState)
    {
        auto result = ref new PresetGetPresetResult();
        result->Status = Windows::Devices::AllJoyn::AllJoynStatus::Ok;
        result->ResponseCode = interfaceMemberResponseCode;
        result->PresetID = interfaceMemberPresetID;
        result->LampState = interfaceMemberLampState;
        result->m_creationContext = Concurrency::task_continuation_context::use_current();
        return result;
    }
    
    static PresetGetPresetResult^ CreateFailureResult(_In_ int32 status)
    {
        auto result = ref new PresetGetPresetResult();
        result->Status = status;
        return result;
    }
internal:
    Concurrency::task_continuation_context m_creationContext = Concurrency::task_continuation_context::use_default();

private:
    int32 m_status;
    uint32 m_interfaceMemberResponseCode;
    Platform::String^ m_interfaceMemberPresetID;
    Windows::Foundation::Collections::IMap<Platform::String^,Platform::Object^>^ m_interfaceMemberLampState;
};

public ref class PresetJoinSessionResult sealed
{
public:
    property int32 Status
    {
        int32 get() { return m_status; }
    internal:
        void set(_In_ int32 value) { m_status = value; }
    }

    property PresetConsumer^ Consumer
    {
        PresetConsumer^ get() { return m_consumer; }
    internal:
        void set(_In_ PresetConsumer^ value) { m_consumer = value; }
    };

private:
    int32 m_status;
    PresetConsumer^ m_consumer;
};

public ref class PresetGetVersionResult sealed
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

    static PresetGetVersionResult^ CreateSuccessResult(_In_ uint32 value)
    {
        auto result = ref new PresetGetVersionResult();
        result->Status = Windows::Devices::AllJoyn::AllJoynStatus::Ok;
        result->Version = value;
        result->m_creationContext = Concurrency::task_continuation_context::use_current();
        return result;
    }

    static PresetGetVersionResult^ CreateFailureResult(_In_ int32 status)
    {
        auto result = ref new PresetGetVersionResult();
        result->Status = status;
        return result;
    }
internal:
    Concurrency::task_continuation_context m_creationContext = Concurrency::task_continuation_context::use_default();

private:
    int32 m_status;
    uint32 m_value;
};

} } } } } 