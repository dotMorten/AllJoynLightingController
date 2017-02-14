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

using namespace concurrency;

namespace org { namespace allseen { namespace LSF { namespace ControllerService { namespace MasterScene {

ref class MasterSceneConsumer;

public ref class MasterSceneGetAllMasterSceneIDsResult sealed
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
    property Windows::Foundation::Collections::IVector<Platform::String^>^ MasterSceneIDs
    {
        Windows::Foundation::Collections::IVector<Platform::String^>^ get() { return m_interfaceMemberMasterSceneIDs; }
    internal:
        void set(_In_ Windows::Foundation::Collections::IVector<Platform::String^>^ value) { m_interfaceMemberMasterSceneIDs = value; }
    }
    
    static MasterSceneGetAllMasterSceneIDsResult^ CreateSuccessResult(_In_ uint32 interfaceMemberResponseCode, _In_ Windows::Foundation::Collections::IVector<Platform::String^>^ interfaceMemberMasterSceneIDs)
    {
        auto result = ref new MasterSceneGetAllMasterSceneIDsResult();
        result->Status = Windows::Devices::AllJoyn::AllJoynStatus::Ok;
        result->ResponseCode = interfaceMemberResponseCode;
        result->MasterSceneIDs = interfaceMemberMasterSceneIDs;
        result->m_creationContext = Concurrency::task_continuation_context::use_current();
        return result;
    }
    
    static MasterSceneGetAllMasterSceneIDsResult^ CreateFailureResult(_In_ int32 status)
    {
        auto result = ref new MasterSceneGetAllMasterSceneIDsResult();
        result->Status = status;
        return result;
    }
internal:
    Concurrency::task_continuation_context m_creationContext = Concurrency::task_continuation_context::use_default();

private:
    int32 m_status;
    uint32 m_interfaceMemberResponseCode;
    Windows::Foundation::Collections::IVector<Platform::String^>^ m_interfaceMemberMasterSceneIDs;
};

public ref class MasterSceneGetMasterSceneNameResult sealed
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
    property Platform::String^ MasterSceneID
    {
        Platform::String^ get() { return m_interfaceMemberMasterSceneID; }
    internal:
        void set(_In_ Platform::String^ value) { m_interfaceMemberMasterSceneID = value; }
    }
    property Platform::String^ Language
    {
        Platform::String^ get() { return m_interfaceMemberLanguage; }
    internal:
        void set(_In_ Platform::String^ value) { m_interfaceMemberLanguage = value; }
    }
    property Platform::String^ MasterSceneName
    {
        Platform::String^ get() { return m_interfaceMemberMasterSceneName; }
    internal:
        void set(_In_ Platform::String^ value) { m_interfaceMemberMasterSceneName = value; }
    }
    
    static MasterSceneGetMasterSceneNameResult^ CreateSuccessResult(_In_ uint32 interfaceMemberResponseCode, _In_ Platform::String^ interfaceMemberMasterSceneID, _In_ Platform::String^ interfaceMemberLanguage, _In_ Platform::String^ interfaceMemberMasterSceneName)
    {
        auto result = ref new MasterSceneGetMasterSceneNameResult();
        result->Status = Windows::Devices::AllJoyn::AllJoynStatus::Ok;
        result->ResponseCode = interfaceMemberResponseCode;
        result->MasterSceneID = interfaceMemberMasterSceneID;
        result->Language = interfaceMemberLanguage;
        result->MasterSceneName = interfaceMemberMasterSceneName;
        result->m_creationContext = Concurrency::task_continuation_context::use_current();
        return result;
    }
    
    static MasterSceneGetMasterSceneNameResult^ CreateFailureResult(_In_ int32 status)
    {
        auto result = ref new MasterSceneGetMasterSceneNameResult();
        result->Status = status;
        return result;
    }
internal:
    Concurrency::task_continuation_context m_creationContext = Concurrency::task_continuation_context::use_default();

private:
    int32 m_status;
    uint32 m_interfaceMemberResponseCode;
    Platform::String^ m_interfaceMemberMasterSceneID;
    Platform::String^ m_interfaceMemberLanguage;
    Platform::String^ m_interfaceMemberMasterSceneName;
};

public ref class MasterSceneSetMasterSceneNameResult sealed
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
    property Platform::String^ MasterSceneID
    {
        Platform::String^ get() { return m_interfaceMemberMasterSceneID; }
    internal:
        void set(_In_ Platform::String^ value) { m_interfaceMemberMasterSceneID = value; }
    }
    property Platform::String^ Language
    {
        Platform::String^ get() { return m_interfaceMemberLanguage; }
    internal:
        void set(_In_ Platform::String^ value) { m_interfaceMemberLanguage = value; }
    }
    
    static MasterSceneSetMasterSceneNameResult^ CreateSuccessResult(_In_ uint32 interfaceMemberResponseCode, _In_ Platform::String^ interfaceMemberMasterSceneID, _In_ Platform::String^ interfaceMemberLanguage)
    {
        auto result = ref new MasterSceneSetMasterSceneNameResult();
        result->Status = Windows::Devices::AllJoyn::AllJoynStatus::Ok;
        result->ResponseCode = interfaceMemberResponseCode;
        result->MasterSceneID = interfaceMemberMasterSceneID;
        result->Language = interfaceMemberLanguage;
        result->m_creationContext = Concurrency::task_continuation_context::use_current();
        return result;
    }
    
    static MasterSceneSetMasterSceneNameResult^ CreateFailureResult(_In_ int32 status)
    {
        auto result = ref new MasterSceneSetMasterSceneNameResult();
        result->Status = status;
        return result;
    }
internal:
    Concurrency::task_continuation_context m_creationContext = Concurrency::task_continuation_context::use_default();

private:
    int32 m_status;
    uint32 m_interfaceMemberResponseCode;
    Platform::String^ m_interfaceMemberMasterSceneID;
    Platform::String^ m_interfaceMemberLanguage;
};

public ref class MasterSceneCreateMasterSceneResult sealed
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
    property Platform::String^ MasterSceneID
    {
        Platform::String^ get() { return m_interfaceMemberMasterSceneID; }
    internal:
        void set(_In_ Platform::String^ value) { m_interfaceMemberMasterSceneID = value; }
    }
    
    static MasterSceneCreateMasterSceneResult^ CreateSuccessResult(_In_ uint32 interfaceMemberResponseCode, _In_ Platform::String^ interfaceMemberMasterSceneID)
    {
        auto result = ref new MasterSceneCreateMasterSceneResult();
        result->Status = Windows::Devices::AllJoyn::AllJoynStatus::Ok;
        result->ResponseCode = interfaceMemberResponseCode;
        result->MasterSceneID = interfaceMemberMasterSceneID;
        result->m_creationContext = Concurrency::task_continuation_context::use_current();
        return result;
    }
    
    static MasterSceneCreateMasterSceneResult^ CreateFailureResult(_In_ int32 status)
    {
        auto result = ref new MasterSceneCreateMasterSceneResult();
        result->Status = status;
        return result;
    }
internal:
    Concurrency::task_continuation_context m_creationContext = Concurrency::task_continuation_context::use_default();

private:
    int32 m_status;
    uint32 m_interfaceMemberResponseCode;
    Platform::String^ m_interfaceMemberMasterSceneID;
};

public ref class MasterSceneUpdateMasterSceneResult sealed
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
    property Platform::String^ MasterSceneID
    {
        Platform::String^ get() { return m_interfaceMemberMasterSceneID; }
    internal:
        void set(_In_ Platform::String^ value) { m_interfaceMemberMasterSceneID = value; }
    }
    
    static MasterSceneUpdateMasterSceneResult^ CreateSuccessResult(_In_ uint32 interfaceMemberResponseCode, _In_ Platform::String^ interfaceMemberMasterSceneID)
    {
        auto result = ref new MasterSceneUpdateMasterSceneResult();
        result->Status = Windows::Devices::AllJoyn::AllJoynStatus::Ok;
        result->ResponseCode = interfaceMemberResponseCode;
        result->MasterSceneID = interfaceMemberMasterSceneID;
        result->m_creationContext = Concurrency::task_continuation_context::use_current();
        return result;
    }
    
    static MasterSceneUpdateMasterSceneResult^ CreateFailureResult(_In_ int32 status)
    {
        auto result = ref new MasterSceneUpdateMasterSceneResult();
        result->Status = status;
        return result;
    }
internal:
    Concurrency::task_continuation_context m_creationContext = Concurrency::task_continuation_context::use_default();

private:
    int32 m_status;
    uint32 m_interfaceMemberResponseCode;
    Platform::String^ m_interfaceMemberMasterSceneID;
};

public ref class MasterSceneDeleteMasterSceneResult sealed
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
    property Platform::String^ MasterSceneID
    {
        Platform::String^ get() { return m_interfaceMemberMasterSceneID; }
    internal:
        void set(_In_ Platform::String^ value) { m_interfaceMemberMasterSceneID = value; }
    }
    
    static MasterSceneDeleteMasterSceneResult^ CreateSuccessResult(_In_ uint32 interfaceMemberResponseCode, _In_ Platform::String^ interfaceMemberMasterSceneID)
    {
        auto result = ref new MasterSceneDeleteMasterSceneResult();
        result->Status = Windows::Devices::AllJoyn::AllJoynStatus::Ok;
        result->ResponseCode = interfaceMemberResponseCode;
        result->MasterSceneID = interfaceMemberMasterSceneID;
        result->m_creationContext = Concurrency::task_continuation_context::use_current();
        return result;
    }
    
    static MasterSceneDeleteMasterSceneResult^ CreateFailureResult(_In_ int32 status)
    {
        auto result = ref new MasterSceneDeleteMasterSceneResult();
        result->Status = status;
        return result;
    }
internal:
    Concurrency::task_continuation_context m_creationContext = Concurrency::task_continuation_context::use_default();

private:
    int32 m_status;
    uint32 m_interfaceMemberResponseCode;
    Platform::String^ m_interfaceMemberMasterSceneID;
};

public ref class MasterSceneGetMasterSceneResult sealed
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
    property Platform::String^ MasterSceneID
    {
        Platform::String^ get() { return m_interfaceMemberMasterSceneID; }
    internal:
        void set(_In_ Platform::String^ value) { m_interfaceMemberMasterSceneID = value; }
    }
    property Windows::Foundation::Collections::IVector<Platform::String^>^ Scenes
    {
        Windows::Foundation::Collections::IVector<Platform::String^>^ get() { return m_interfaceMemberScenes; }
    internal:
        void set(_In_ Windows::Foundation::Collections::IVector<Platform::String^>^ value) { m_interfaceMemberScenes = value; }
    }
    
    static MasterSceneGetMasterSceneResult^ CreateSuccessResult(_In_ uint32 interfaceMemberResponseCode, _In_ Platform::String^ interfaceMemberMasterSceneID, _In_ Windows::Foundation::Collections::IVector<Platform::String^>^ interfaceMemberScenes)
    {
        auto result = ref new MasterSceneGetMasterSceneResult();
        result->Status = Windows::Devices::AllJoyn::AllJoynStatus::Ok;
        result->ResponseCode = interfaceMemberResponseCode;
        result->MasterSceneID = interfaceMemberMasterSceneID;
        result->Scenes = interfaceMemberScenes;
        result->m_creationContext = Concurrency::task_continuation_context::use_current();
        return result;
    }
    
    static MasterSceneGetMasterSceneResult^ CreateFailureResult(_In_ int32 status)
    {
        auto result = ref new MasterSceneGetMasterSceneResult();
        result->Status = status;
        return result;
    }
internal:
    Concurrency::task_continuation_context m_creationContext = Concurrency::task_continuation_context::use_default();

private:
    int32 m_status;
    uint32 m_interfaceMemberResponseCode;
    Platform::String^ m_interfaceMemberMasterSceneID;
    Windows::Foundation::Collections::IVector<Platform::String^>^ m_interfaceMemberScenes;
};

public ref class MasterSceneApplyMasterSceneResult sealed
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
    property Platform::String^ MasterSceneID
    {
        Platform::String^ get() { return m_interfaceMemberMasterSceneID; }
    internal:
        void set(_In_ Platform::String^ value) { m_interfaceMemberMasterSceneID = value; }
    }
    
    static MasterSceneApplyMasterSceneResult^ CreateSuccessResult(_In_ uint32 interfaceMemberResponseCode, _In_ Platform::String^ interfaceMemberMasterSceneID)
    {
        auto result = ref new MasterSceneApplyMasterSceneResult();
        result->Status = Windows::Devices::AllJoyn::AllJoynStatus::Ok;
        result->ResponseCode = interfaceMemberResponseCode;
        result->MasterSceneID = interfaceMemberMasterSceneID;
        result->m_creationContext = Concurrency::task_continuation_context::use_current();
        return result;
    }
    
    static MasterSceneApplyMasterSceneResult^ CreateFailureResult(_In_ int32 status)
    {
        auto result = ref new MasterSceneApplyMasterSceneResult();
        result->Status = status;
        return result;
    }
internal:
    Concurrency::task_continuation_context m_creationContext = Concurrency::task_continuation_context::use_default();

private:
    int32 m_status;
    uint32 m_interfaceMemberResponseCode;
    Platform::String^ m_interfaceMemberMasterSceneID;
};

public ref class MasterSceneJoinSessionResult sealed
{
public:
    property int32 Status
    {
        int32 get() { return m_status; }
    internal:
        void set(_In_ int32 value) { m_status = value; }
    }

    property MasterSceneConsumer^ Consumer
    {
        MasterSceneConsumer^ get() { return m_consumer; }
    internal:
        void set(_In_ MasterSceneConsumer^ value) { m_consumer = value; }
    };

private:
    int32 m_status;
    MasterSceneConsumer^ m_consumer;
};

public ref class MasterSceneGetVersionResult sealed
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

    static MasterSceneGetVersionResult^ CreateSuccessResult(_In_ uint32 value)
    {
        auto result = ref new MasterSceneGetVersionResult();
        result->Status = Windows::Devices::AllJoyn::AllJoynStatus::Ok;
        result->Version = value;
        result->m_creationContext = Concurrency::task_continuation_context::use_current();
        return result;
    }

    static MasterSceneGetVersionResult^ CreateFailureResult(_In_ int32 status)
    {
        auto result = ref new MasterSceneGetVersionResult();
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
