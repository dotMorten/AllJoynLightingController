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

namespace org { namespace allseen { namespace LSF { namespace ControllerService { namespace Lamp {

// Methods
public ref class LampGetAllLampIDsCalledEventArgs sealed
{
public:
    LampGetAllLampIDsCalledEventArgs(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info);

    property Windows::Devices::AllJoyn::AllJoynMessageInfo^ MessageInfo
    {
        Windows::Devices::AllJoyn::AllJoynMessageInfo^ get() { return m_messageInfo; }
    }

    property LampGetAllLampIDsResult^ Result
    {
        LampGetAllLampIDsResult^ get() { return m_result; }
        void set(_In_ LampGetAllLampIDsResult^ value) { m_result = value; }
    }

    Windows::Foundation::Deferral^ GetDeferral();

    static Windows::Foundation::IAsyncOperation<LampGetAllLampIDsResult^>^ GetResultAsync(LampGetAllLampIDsCalledEventArgs^ args)
    {
        args->InvokeAllFinished();
        auto t = concurrency::create_task(args->m_tce);
        return concurrency::create_async([t]() -> concurrency::task<LampGetAllLampIDsResult^>
        {
            return t;
        });
    }
    
private:
    void Complete();
    void InvokeAllFinished();
    void InvokeCompleteHandler();

    bool m_raised;
    int m_completionsRequired;
    concurrency::task_completion_event<LampGetAllLampIDsResult^> m_tce;
    std::mutex m_lock;
    Windows::Devices::AllJoyn::AllJoynMessageInfo^ m_messageInfo;
    LampGetAllLampIDsResult^ m_result;
};

public ref class LampGetLampSupportedLanguagesCalledEventArgs sealed
{
public:
    LampGetLampSupportedLanguagesCalledEventArgs(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampID);

    property Windows::Devices::AllJoyn::AllJoynMessageInfo^ MessageInfo
    {
        Windows::Devices::AllJoyn::AllJoynMessageInfo^ get() { return m_messageInfo; }
    }

    property LampGetLampSupportedLanguagesResult^ Result
    {
        LampGetLampSupportedLanguagesResult^ get() { return m_result; }
        void set(_In_ LampGetLampSupportedLanguagesResult^ value) { m_result = value; }
    }

    property Platform::String^ LampID
    {
        Platform::String^ get() { return m_interfaceMemberLampID; }
    }

    Windows::Foundation::Deferral^ GetDeferral();

    static Windows::Foundation::IAsyncOperation<LampGetLampSupportedLanguagesResult^>^ GetResultAsync(LampGetLampSupportedLanguagesCalledEventArgs^ args)
    {
        args->InvokeAllFinished();
        auto t = concurrency::create_task(args->m_tce);
        return concurrency::create_async([t]() -> concurrency::task<LampGetLampSupportedLanguagesResult^>
        {
            return t;
        });
    }
    
private:
    void Complete();
    void InvokeAllFinished();
    void InvokeCompleteHandler();

    bool m_raised;
    int m_completionsRequired;
    concurrency::task_completion_event<LampGetLampSupportedLanguagesResult^> m_tce;
    std::mutex m_lock;
    Windows::Devices::AllJoyn::AllJoynMessageInfo^ m_messageInfo;
    LampGetLampSupportedLanguagesResult^ m_result;
    Platform::String^ m_interfaceMemberLampID;
};

public ref class LampGetLampManufacturerCalledEventArgs sealed
{
public:
    LampGetLampManufacturerCalledEventArgs(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampID, _In_ Platform::String^ interfaceMemberLanguage);

    property Windows::Devices::AllJoyn::AllJoynMessageInfo^ MessageInfo
    {
        Windows::Devices::AllJoyn::AllJoynMessageInfo^ get() { return m_messageInfo; }
    }

    property LampGetLampManufacturerResult^ Result
    {
        LampGetLampManufacturerResult^ get() { return m_result; }
        void set(_In_ LampGetLampManufacturerResult^ value) { m_result = value; }
    }

    property Platform::String^ LampID
    {
        Platform::String^ get() { return m_interfaceMemberLampID; }
    }

    property Platform::String^ Language
    {
        Platform::String^ get() { return m_interfaceMemberLanguage; }
    }

    Windows::Foundation::Deferral^ GetDeferral();

    static Windows::Foundation::IAsyncOperation<LampGetLampManufacturerResult^>^ GetResultAsync(LampGetLampManufacturerCalledEventArgs^ args)
    {
        args->InvokeAllFinished();
        auto t = concurrency::create_task(args->m_tce);
        return concurrency::create_async([t]() -> concurrency::task<LampGetLampManufacturerResult^>
        {
            return t;
        });
    }
    
private:
    void Complete();
    void InvokeAllFinished();
    void InvokeCompleteHandler();

    bool m_raised;
    int m_completionsRequired;
    concurrency::task_completion_event<LampGetLampManufacturerResult^> m_tce;
    std::mutex m_lock;
    Windows::Devices::AllJoyn::AllJoynMessageInfo^ m_messageInfo;
    LampGetLampManufacturerResult^ m_result;
    Platform::String^ m_interfaceMemberLampID;
    Platform::String^ m_interfaceMemberLanguage;
};

public ref class LampGetLampNameCalledEventArgs sealed
{
public:
    LampGetLampNameCalledEventArgs(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampID, _In_ Platform::String^ interfaceMemberLanguage);

    property Windows::Devices::AllJoyn::AllJoynMessageInfo^ MessageInfo
    {
        Windows::Devices::AllJoyn::AllJoynMessageInfo^ get() { return m_messageInfo; }
    }

    property LampGetLampNameResult^ Result
    {
        LampGetLampNameResult^ get() { return m_result; }
        void set(_In_ LampGetLampNameResult^ value) { m_result = value; }
    }

    property Platform::String^ LampID
    {
        Platform::String^ get() { return m_interfaceMemberLampID; }
    }

    property Platform::String^ Language
    {
        Platform::String^ get() { return m_interfaceMemberLanguage; }
    }

    Windows::Foundation::Deferral^ GetDeferral();

    static Windows::Foundation::IAsyncOperation<LampGetLampNameResult^>^ GetResultAsync(LampGetLampNameCalledEventArgs^ args)
    {
        args->InvokeAllFinished();
        auto t = concurrency::create_task(args->m_tce);
        return concurrency::create_async([t]() -> concurrency::task<LampGetLampNameResult^>
        {
            return t;
        });
    }
    
private:
    void Complete();
    void InvokeAllFinished();
    void InvokeCompleteHandler();

    bool m_raised;
    int m_completionsRequired;
    concurrency::task_completion_event<LampGetLampNameResult^> m_tce;
    std::mutex m_lock;
    Windows::Devices::AllJoyn::AllJoynMessageInfo^ m_messageInfo;
    LampGetLampNameResult^ m_result;
    Platform::String^ m_interfaceMemberLampID;
    Platform::String^ m_interfaceMemberLanguage;
};

public ref class LampSetLampNameCalledEventArgs sealed
{
public:
    LampSetLampNameCalledEventArgs(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampID, _In_ Platform::String^ interfaceMemberLampName, _In_ Platform::String^ interfaceMemberLanguage);

    property Windows::Devices::AllJoyn::AllJoynMessageInfo^ MessageInfo
    {
        Windows::Devices::AllJoyn::AllJoynMessageInfo^ get() { return m_messageInfo; }
    }

    property LampSetLampNameResult^ Result
    {
        LampSetLampNameResult^ get() { return m_result; }
        void set(_In_ LampSetLampNameResult^ value) { m_result = value; }
    }

    property Platform::String^ LampID
    {
        Platform::String^ get() { return m_interfaceMemberLampID; }
    }

    property Platform::String^ LampName
    {
        Platform::String^ get() { return m_interfaceMemberLampName; }
    }

    property Platform::String^ Language
    {
        Platform::String^ get() { return m_interfaceMemberLanguage; }
    }

    Windows::Foundation::Deferral^ GetDeferral();

    static Windows::Foundation::IAsyncOperation<LampSetLampNameResult^>^ GetResultAsync(LampSetLampNameCalledEventArgs^ args)
    {
        args->InvokeAllFinished();
        auto t = concurrency::create_task(args->m_tce);
        return concurrency::create_async([t]() -> concurrency::task<LampSetLampNameResult^>
        {
            return t;
        });
    }
    
private:
    void Complete();
    void InvokeAllFinished();
    void InvokeCompleteHandler();

    bool m_raised;
    int m_completionsRequired;
    concurrency::task_completion_event<LampSetLampNameResult^> m_tce;
    std::mutex m_lock;
    Windows::Devices::AllJoyn::AllJoynMessageInfo^ m_messageInfo;
    LampSetLampNameResult^ m_result;
    Platform::String^ m_interfaceMemberLampID;
    Platform::String^ m_interfaceMemberLampName;
    Platform::String^ m_interfaceMemberLanguage;
};

public ref class LampGetLampDetailsCalledEventArgs sealed
{
public:
    LampGetLampDetailsCalledEventArgs(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampID);

    property Windows::Devices::AllJoyn::AllJoynMessageInfo^ MessageInfo
    {
        Windows::Devices::AllJoyn::AllJoynMessageInfo^ get() { return m_messageInfo; }
    }

    property LampGetLampDetailsResult^ Result
    {
        LampGetLampDetailsResult^ get() { return m_result; }
        void set(_In_ LampGetLampDetailsResult^ value) { m_result = value; }
    }

    property Platform::String^ LampID
    {
        Platform::String^ get() { return m_interfaceMemberLampID; }
    }

    Windows::Foundation::Deferral^ GetDeferral();

    static Windows::Foundation::IAsyncOperation<LampGetLampDetailsResult^>^ GetResultAsync(LampGetLampDetailsCalledEventArgs^ args)
    {
        args->InvokeAllFinished();
        auto t = concurrency::create_task(args->m_tce);
        return concurrency::create_async([t]() -> concurrency::task<LampGetLampDetailsResult^>
        {
            return t;
        });
    }
    
private:
    void Complete();
    void InvokeAllFinished();
    void InvokeCompleteHandler();

    bool m_raised;
    int m_completionsRequired;
    concurrency::task_completion_event<LampGetLampDetailsResult^> m_tce;
    std::mutex m_lock;
    Windows::Devices::AllJoyn::AllJoynMessageInfo^ m_messageInfo;
    LampGetLampDetailsResult^ m_result;
    Platform::String^ m_interfaceMemberLampID;
};

public ref class LampGetLampParametersCalledEventArgs sealed
{
public:
    LampGetLampParametersCalledEventArgs(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampID);

    property Windows::Devices::AllJoyn::AllJoynMessageInfo^ MessageInfo
    {
        Windows::Devices::AllJoyn::AllJoynMessageInfo^ get() { return m_messageInfo; }
    }

    property LampGetLampParametersResult^ Result
    {
        LampGetLampParametersResult^ get() { return m_result; }
        void set(_In_ LampGetLampParametersResult^ value) { m_result = value; }
    }

    property Platform::String^ LampID
    {
        Platform::String^ get() { return m_interfaceMemberLampID; }
    }

    Windows::Foundation::Deferral^ GetDeferral();

    static Windows::Foundation::IAsyncOperation<LampGetLampParametersResult^>^ GetResultAsync(LampGetLampParametersCalledEventArgs^ args)
    {
        args->InvokeAllFinished();
        auto t = concurrency::create_task(args->m_tce);
        return concurrency::create_async([t]() -> concurrency::task<LampGetLampParametersResult^>
        {
            return t;
        });
    }
    
private:
    void Complete();
    void InvokeAllFinished();
    void InvokeCompleteHandler();

    bool m_raised;
    int m_completionsRequired;
    concurrency::task_completion_event<LampGetLampParametersResult^> m_tce;
    std::mutex m_lock;
    Windows::Devices::AllJoyn::AllJoynMessageInfo^ m_messageInfo;
    LampGetLampParametersResult^ m_result;
    Platform::String^ m_interfaceMemberLampID;
};

public ref class LampGetLampParametersFieldCalledEventArgs sealed
{
public:
    LampGetLampParametersFieldCalledEventArgs(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampID, _In_ Platform::String^ interfaceMemberLampParameterFieldName);

    property Windows::Devices::AllJoyn::AllJoynMessageInfo^ MessageInfo
    {
        Windows::Devices::AllJoyn::AllJoynMessageInfo^ get() { return m_messageInfo; }
    }

    property LampGetLampParametersFieldResult^ Result
    {
        LampGetLampParametersFieldResult^ get() { return m_result; }
        void set(_In_ LampGetLampParametersFieldResult^ value) { m_result = value; }
    }

    property Platform::String^ LampID
    {
        Platform::String^ get() { return m_interfaceMemberLampID; }
    }

    property Platform::String^ LampParameterFieldName
    {
        Platform::String^ get() { return m_interfaceMemberLampParameterFieldName; }
    }

    Windows::Foundation::Deferral^ GetDeferral();

    static Windows::Foundation::IAsyncOperation<LampGetLampParametersFieldResult^>^ GetResultAsync(LampGetLampParametersFieldCalledEventArgs^ args)
    {
        args->InvokeAllFinished();
        auto t = concurrency::create_task(args->m_tce);
        return concurrency::create_async([t]() -> concurrency::task<LampGetLampParametersFieldResult^>
        {
            return t;
        });
    }
    
private:
    void Complete();
    void InvokeAllFinished();
    void InvokeCompleteHandler();

    bool m_raised;
    int m_completionsRequired;
    concurrency::task_completion_event<LampGetLampParametersFieldResult^> m_tce;
    std::mutex m_lock;
    Windows::Devices::AllJoyn::AllJoynMessageInfo^ m_messageInfo;
    LampGetLampParametersFieldResult^ m_result;
    Platform::String^ m_interfaceMemberLampID;
    Platform::String^ m_interfaceMemberLampParameterFieldName;
};

public ref class LampGetLampStateCalledEventArgs sealed
{
public:
    LampGetLampStateCalledEventArgs(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampID);

    property Windows::Devices::AllJoyn::AllJoynMessageInfo^ MessageInfo
    {
        Windows::Devices::AllJoyn::AllJoynMessageInfo^ get() { return m_messageInfo; }
    }

    property LampGetLampStateResult^ Result
    {
        LampGetLampStateResult^ get() { return m_result; }
        void set(_In_ LampGetLampStateResult^ value) { m_result = value; }
    }

    property Platform::String^ LampID
    {
        Platform::String^ get() { return m_interfaceMemberLampID; }
    }

    Windows::Foundation::Deferral^ GetDeferral();

    static Windows::Foundation::IAsyncOperation<LampGetLampStateResult^>^ GetResultAsync(LampGetLampStateCalledEventArgs^ args)
    {
        args->InvokeAllFinished();
        auto t = concurrency::create_task(args->m_tce);
        return concurrency::create_async([t]() -> concurrency::task<LampGetLampStateResult^>
        {
            return t;
        });
    }
    
private:
    void Complete();
    void InvokeAllFinished();
    void InvokeCompleteHandler();

    bool m_raised;
    int m_completionsRequired;
    concurrency::task_completion_event<LampGetLampStateResult^> m_tce;
    std::mutex m_lock;
    Windows::Devices::AllJoyn::AllJoynMessageInfo^ m_messageInfo;
    LampGetLampStateResult^ m_result;
    Platform::String^ m_interfaceMemberLampID;
};

public ref class LampGetLampStateFieldCalledEventArgs sealed
{
public:
    LampGetLampStateFieldCalledEventArgs(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampID, _In_ Platform::String^ interfaceMemberLampStateFieldName);

    property Windows::Devices::AllJoyn::AllJoynMessageInfo^ MessageInfo
    {
        Windows::Devices::AllJoyn::AllJoynMessageInfo^ get() { return m_messageInfo; }
    }

    property LampGetLampStateFieldResult^ Result
    {
        LampGetLampStateFieldResult^ get() { return m_result; }
        void set(_In_ LampGetLampStateFieldResult^ value) { m_result = value; }
    }

    property Platform::String^ LampID
    {
        Platform::String^ get() { return m_interfaceMemberLampID; }
    }

    property Platform::String^ LampStateFieldName
    {
        Platform::String^ get() { return m_interfaceMemberLampStateFieldName; }
    }

    Windows::Foundation::Deferral^ GetDeferral();

    static Windows::Foundation::IAsyncOperation<LampGetLampStateFieldResult^>^ GetResultAsync(LampGetLampStateFieldCalledEventArgs^ args)
    {
        args->InvokeAllFinished();
        auto t = concurrency::create_task(args->m_tce);
        return concurrency::create_async([t]() -> concurrency::task<LampGetLampStateFieldResult^>
        {
            return t;
        });
    }
    
private:
    void Complete();
    void InvokeAllFinished();
    void InvokeCompleteHandler();

    bool m_raised;
    int m_completionsRequired;
    concurrency::task_completion_event<LampGetLampStateFieldResult^> m_tce;
    std::mutex m_lock;
    Windows::Devices::AllJoyn::AllJoynMessageInfo^ m_messageInfo;
    LampGetLampStateFieldResult^ m_result;
    Platform::String^ m_interfaceMemberLampID;
    Platform::String^ m_interfaceMemberLampStateFieldName;
};

public ref class LampTransitionLampStateCalledEventArgs sealed
{
public:
    LampTransitionLampStateCalledEventArgs(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampID, _In_ Windows::Foundation::Collections::IMapView<Platform::String^,Platform::Object^>^ interfaceMemberLampState, _In_ uint32 interfaceMemberTransitionPeriod);

    property Windows::Devices::AllJoyn::AllJoynMessageInfo^ MessageInfo
    {
        Windows::Devices::AllJoyn::AllJoynMessageInfo^ get() { return m_messageInfo; }
    }

    property LampTransitionLampStateResult^ Result
    {
        LampTransitionLampStateResult^ get() { return m_result; }
        void set(_In_ LampTransitionLampStateResult^ value) { m_result = value; }
    }

    property Platform::String^ LampID
    {
        Platform::String^ get() { return m_interfaceMemberLampID; }
    }

    property Windows::Foundation::Collections::IMapView<Platform::String^,Platform::Object^>^ LampState
    {
        Windows::Foundation::Collections::IMapView<Platform::String^,Platform::Object^>^ get() { return m_interfaceMemberLampState; }
    }

    property uint32 TransitionPeriod
    {
        uint32 get() { return m_interfaceMemberTransitionPeriod; }
    }

    Windows::Foundation::Deferral^ GetDeferral();

    static Windows::Foundation::IAsyncOperation<LampTransitionLampStateResult^>^ GetResultAsync(LampTransitionLampStateCalledEventArgs^ args)
    {
        args->InvokeAllFinished();
        auto t = concurrency::create_task(args->m_tce);
        return concurrency::create_async([t]() -> concurrency::task<LampTransitionLampStateResult^>
        {
            return t;
        });
    }
    
private:
    void Complete();
    void InvokeAllFinished();
    void InvokeCompleteHandler();

    bool m_raised;
    int m_completionsRequired;
    concurrency::task_completion_event<LampTransitionLampStateResult^> m_tce;
    std::mutex m_lock;
    Windows::Devices::AllJoyn::AllJoynMessageInfo^ m_messageInfo;
    LampTransitionLampStateResult^ m_result;
    Platform::String^ m_interfaceMemberLampID;
    Windows::Foundation::Collections::IMapView<Platform::String^,Platform::Object^>^ m_interfaceMemberLampState;
    uint32 m_interfaceMemberTransitionPeriod;
};

public ref class LampPulseLampWithStateCalledEventArgs sealed
{
public:
    LampPulseLampWithStateCalledEventArgs(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampID, _In_ Windows::Foundation::Collections::IMapView<Platform::String^,Platform::Object^>^ interfaceMemberFromLampState, _In_ Windows::Foundation::Collections::IMapView<Platform::String^,Platform::Object^>^ interfaceMemberToLampState, _In_ uint32 interfaceMemberPeriod, _In_ uint32 interfaceMemberDuration, _In_ uint32 interfaceMemberNumPulses);

    property Windows::Devices::AllJoyn::AllJoynMessageInfo^ MessageInfo
    {
        Windows::Devices::AllJoyn::AllJoynMessageInfo^ get() { return m_messageInfo; }
    }

    property LampPulseLampWithStateResult^ Result
    {
        LampPulseLampWithStateResult^ get() { return m_result; }
        void set(_In_ LampPulseLampWithStateResult^ value) { m_result = value; }
    }

    property Platform::String^ LampID
    {
        Platform::String^ get() { return m_interfaceMemberLampID; }
    }

    property Windows::Foundation::Collections::IMapView<Platform::String^,Platform::Object^>^ FromLampState
    {
        Windows::Foundation::Collections::IMapView<Platform::String^,Platform::Object^>^ get() { return m_interfaceMemberFromLampState; }
    }

    property Windows::Foundation::Collections::IMapView<Platform::String^,Platform::Object^>^ ToLampState
    {
        Windows::Foundation::Collections::IMapView<Platform::String^,Platform::Object^>^ get() { return m_interfaceMemberToLampState; }
    }

    property uint32 Period
    {
        uint32 get() { return m_interfaceMemberPeriod; }
    }

    property uint32 Duration
    {
        uint32 get() { return m_interfaceMemberDuration; }
    }

    property uint32 NumPulses
    {
        uint32 get() { return m_interfaceMemberNumPulses; }
    }

    Windows::Foundation::Deferral^ GetDeferral();

    static Windows::Foundation::IAsyncOperation<LampPulseLampWithStateResult^>^ GetResultAsync(LampPulseLampWithStateCalledEventArgs^ args)
    {
        args->InvokeAllFinished();
        auto t = concurrency::create_task(args->m_tce);
        return concurrency::create_async([t]() -> concurrency::task<LampPulseLampWithStateResult^>
        {
            return t;
        });
    }
    
private:
    void Complete();
    void InvokeAllFinished();
    void InvokeCompleteHandler();

    bool m_raised;
    int m_completionsRequired;
    concurrency::task_completion_event<LampPulseLampWithStateResult^> m_tce;
    std::mutex m_lock;
    Windows::Devices::AllJoyn::AllJoynMessageInfo^ m_messageInfo;
    LampPulseLampWithStateResult^ m_result;
    Platform::String^ m_interfaceMemberLampID;
    Windows::Foundation::Collections::IMapView<Platform::String^,Platform::Object^>^ m_interfaceMemberFromLampState;
    Windows::Foundation::Collections::IMapView<Platform::String^,Platform::Object^>^ m_interfaceMemberToLampState;
    uint32 m_interfaceMemberPeriod;
    uint32 m_interfaceMemberDuration;
    uint32 m_interfaceMemberNumPulses;
};

public ref class LampPulseLampWithPresetCalledEventArgs sealed
{
public:
    LampPulseLampWithPresetCalledEventArgs(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampID, _In_ Platform::String^ interfaceMemberFromPresetID, _In_ Platform::String^ interfaceMemberToPresetID, _In_ uint32 interfaceMemberPeriod, _In_ uint32 interfaceMemberDuration, _In_ uint32 interfaceMemberNumPulses);

    property Windows::Devices::AllJoyn::AllJoynMessageInfo^ MessageInfo
    {
        Windows::Devices::AllJoyn::AllJoynMessageInfo^ get() { return m_messageInfo; }
    }

    property LampPulseLampWithPresetResult^ Result
    {
        LampPulseLampWithPresetResult^ get() { return m_result; }
        void set(_In_ LampPulseLampWithPresetResult^ value) { m_result = value; }
    }

    property Platform::String^ LampID
    {
        Platform::String^ get() { return m_interfaceMemberLampID; }
    }

    property Platform::String^ FromPresetID
    {
        Platform::String^ get() { return m_interfaceMemberFromPresetID; }
    }

    property Platform::String^ ToPresetID
    {
        Platform::String^ get() { return m_interfaceMemberToPresetID; }
    }

    property uint32 Period
    {
        uint32 get() { return m_interfaceMemberPeriod; }
    }

    property uint32 Duration
    {
        uint32 get() { return m_interfaceMemberDuration; }
    }

    property uint32 NumPulses
    {
        uint32 get() { return m_interfaceMemberNumPulses; }
    }

    Windows::Foundation::Deferral^ GetDeferral();

    static Windows::Foundation::IAsyncOperation<LampPulseLampWithPresetResult^>^ GetResultAsync(LampPulseLampWithPresetCalledEventArgs^ args)
    {
        args->InvokeAllFinished();
        auto t = concurrency::create_task(args->m_tce);
        return concurrency::create_async([t]() -> concurrency::task<LampPulseLampWithPresetResult^>
        {
            return t;
        });
    }
    
private:
    void Complete();
    void InvokeAllFinished();
    void InvokeCompleteHandler();

    bool m_raised;
    int m_completionsRequired;
    concurrency::task_completion_event<LampPulseLampWithPresetResult^> m_tce;
    std::mutex m_lock;
    Windows::Devices::AllJoyn::AllJoynMessageInfo^ m_messageInfo;
    LampPulseLampWithPresetResult^ m_result;
    Platform::String^ m_interfaceMemberLampID;
    Platform::String^ m_interfaceMemberFromPresetID;
    Platform::String^ m_interfaceMemberToPresetID;
    uint32 m_interfaceMemberPeriod;
    uint32 m_interfaceMemberDuration;
    uint32 m_interfaceMemberNumPulses;
};

public ref class LampTransitionLampStateToPresetCalledEventArgs sealed
{
public:
    LampTransitionLampStateToPresetCalledEventArgs(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampID, _In_ Platform::String^ interfaceMemberPresetID, _In_ uint32 interfaceMemberTransitionPeriod);

    property Windows::Devices::AllJoyn::AllJoynMessageInfo^ MessageInfo
    {
        Windows::Devices::AllJoyn::AllJoynMessageInfo^ get() { return m_messageInfo; }
    }

    property LampTransitionLampStateToPresetResult^ Result
    {
        LampTransitionLampStateToPresetResult^ get() { return m_result; }
        void set(_In_ LampTransitionLampStateToPresetResult^ value) { m_result = value; }
    }

    property Platform::String^ LampID
    {
        Platform::String^ get() { return m_interfaceMemberLampID; }
    }

    property Platform::String^ PresetID
    {
        Platform::String^ get() { return m_interfaceMemberPresetID; }
    }

    property uint32 TransitionPeriod
    {
        uint32 get() { return m_interfaceMemberTransitionPeriod; }
    }

    Windows::Foundation::Deferral^ GetDeferral();

    static Windows::Foundation::IAsyncOperation<LampTransitionLampStateToPresetResult^>^ GetResultAsync(LampTransitionLampStateToPresetCalledEventArgs^ args)
    {
        args->InvokeAllFinished();
        auto t = concurrency::create_task(args->m_tce);
        return concurrency::create_async([t]() -> concurrency::task<LampTransitionLampStateToPresetResult^>
        {
            return t;
        });
    }
    
private:
    void Complete();
    void InvokeAllFinished();
    void InvokeCompleteHandler();

    bool m_raised;
    int m_completionsRequired;
    concurrency::task_completion_event<LampTransitionLampStateToPresetResult^> m_tce;
    std::mutex m_lock;
    Windows::Devices::AllJoyn::AllJoynMessageInfo^ m_messageInfo;
    LampTransitionLampStateToPresetResult^ m_result;
    Platform::String^ m_interfaceMemberLampID;
    Platform::String^ m_interfaceMemberPresetID;
    uint32 m_interfaceMemberTransitionPeriod;
};

public ref class LampTransitionLampStateFieldCalledEventArgs sealed
{
public:
    LampTransitionLampStateFieldCalledEventArgs(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampID, _In_ Platform::String^ interfaceMemberLampStateFieldName, _In_ Platform::Object^ interfaceMemberLampStateFieldValue, _In_ uint32 interfaceMemberTransitionPeriod);

    property Windows::Devices::AllJoyn::AllJoynMessageInfo^ MessageInfo
    {
        Windows::Devices::AllJoyn::AllJoynMessageInfo^ get() { return m_messageInfo; }
    }

    property LampTransitionLampStateFieldResult^ Result
    {
        LampTransitionLampStateFieldResult^ get() { return m_result; }
        void set(_In_ LampTransitionLampStateFieldResult^ value) { m_result = value; }
    }

    property Platform::String^ LampID
    {
        Platform::String^ get() { return m_interfaceMemberLampID; }
    }

    property Platform::String^ LampStateFieldName
    {
        Platform::String^ get() { return m_interfaceMemberLampStateFieldName; }
    }

    property Platform::Object^ LampStateFieldValue
    {
        Platform::Object^ get() { return m_interfaceMemberLampStateFieldValue; }
    }

    property uint32 TransitionPeriod
    {
        uint32 get() { return m_interfaceMemberTransitionPeriod; }
    }

    Windows::Foundation::Deferral^ GetDeferral();

    static Windows::Foundation::IAsyncOperation<LampTransitionLampStateFieldResult^>^ GetResultAsync(LampTransitionLampStateFieldCalledEventArgs^ args)
    {
        args->InvokeAllFinished();
        auto t = concurrency::create_task(args->m_tce);
        return concurrency::create_async([t]() -> concurrency::task<LampTransitionLampStateFieldResult^>
        {
            return t;
        });
    }
    
private:
    void Complete();
    void InvokeAllFinished();
    void InvokeCompleteHandler();

    bool m_raised;
    int m_completionsRequired;
    concurrency::task_completion_event<LampTransitionLampStateFieldResult^> m_tce;
    std::mutex m_lock;
    Windows::Devices::AllJoyn::AllJoynMessageInfo^ m_messageInfo;
    LampTransitionLampStateFieldResult^ m_result;
    Platform::String^ m_interfaceMemberLampID;
    Platform::String^ m_interfaceMemberLampStateFieldName;
    Platform::Object^ m_interfaceMemberLampStateFieldValue;
    uint32 m_interfaceMemberTransitionPeriod;
};

public ref class LampResetLampStateCalledEventArgs sealed
{
public:
    LampResetLampStateCalledEventArgs(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampID);

    property Windows::Devices::AllJoyn::AllJoynMessageInfo^ MessageInfo
    {
        Windows::Devices::AllJoyn::AllJoynMessageInfo^ get() { return m_messageInfo; }
    }

    property LampResetLampStateResult^ Result
    {
        LampResetLampStateResult^ get() { return m_result; }
        void set(_In_ LampResetLampStateResult^ value) { m_result = value; }
    }

    property Platform::String^ LampID
    {
        Platform::String^ get() { return m_interfaceMemberLampID; }
    }

    Windows::Foundation::Deferral^ GetDeferral();

    static Windows::Foundation::IAsyncOperation<LampResetLampStateResult^>^ GetResultAsync(LampResetLampStateCalledEventArgs^ args)
    {
        args->InvokeAllFinished();
        auto t = concurrency::create_task(args->m_tce);
        return concurrency::create_async([t]() -> concurrency::task<LampResetLampStateResult^>
        {
            return t;
        });
    }
    
private:
    void Complete();
    void InvokeAllFinished();
    void InvokeCompleteHandler();

    bool m_raised;
    int m_completionsRequired;
    concurrency::task_completion_event<LampResetLampStateResult^> m_tce;
    std::mutex m_lock;
    Windows::Devices::AllJoyn::AllJoynMessageInfo^ m_messageInfo;
    LampResetLampStateResult^ m_result;
    Platform::String^ m_interfaceMemberLampID;
};

public ref class LampResetLampStateFieldCalledEventArgs sealed
{
public:
    LampResetLampStateFieldCalledEventArgs(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampID, _In_ Platform::String^ interfaceMemberLampStateFieldName);

    property Windows::Devices::AllJoyn::AllJoynMessageInfo^ MessageInfo
    {
        Windows::Devices::AllJoyn::AllJoynMessageInfo^ get() { return m_messageInfo; }
    }

    property LampResetLampStateFieldResult^ Result
    {
        LampResetLampStateFieldResult^ get() { return m_result; }
        void set(_In_ LampResetLampStateFieldResult^ value) { m_result = value; }
    }

    property Platform::String^ LampID
    {
        Platform::String^ get() { return m_interfaceMemberLampID; }
    }

    property Platform::String^ LampStateFieldName
    {
        Platform::String^ get() { return m_interfaceMemberLampStateFieldName; }
    }

    Windows::Foundation::Deferral^ GetDeferral();

    static Windows::Foundation::IAsyncOperation<LampResetLampStateFieldResult^>^ GetResultAsync(LampResetLampStateFieldCalledEventArgs^ args)
    {
        args->InvokeAllFinished();
        auto t = concurrency::create_task(args->m_tce);
        return concurrency::create_async([t]() -> concurrency::task<LampResetLampStateFieldResult^>
        {
            return t;
        });
    }
    
private:
    void Complete();
    void InvokeAllFinished();
    void InvokeCompleteHandler();

    bool m_raised;
    int m_completionsRequired;
    concurrency::task_completion_event<LampResetLampStateFieldResult^> m_tce;
    std::mutex m_lock;
    Windows::Devices::AllJoyn::AllJoynMessageInfo^ m_messageInfo;
    LampResetLampStateFieldResult^ m_result;
    Platform::String^ m_interfaceMemberLampID;
    Platform::String^ m_interfaceMemberLampStateFieldName;
};

public ref class LampGetLampFaultsCalledEventArgs sealed
{
public:
    LampGetLampFaultsCalledEventArgs(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampID);

    property Windows::Devices::AllJoyn::AllJoynMessageInfo^ MessageInfo
    {
        Windows::Devices::AllJoyn::AllJoynMessageInfo^ get() { return m_messageInfo; }
    }

    property LampGetLampFaultsResult^ Result
    {
        LampGetLampFaultsResult^ get() { return m_result; }
        void set(_In_ LampGetLampFaultsResult^ value) { m_result = value; }
    }

    property Platform::String^ LampID
    {
        Platform::String^ get() { return m_interfaceMemberLampID; }
    }

    Windows::Foundation::Deferral^ GetDeferral();

    static Windows::Foundation::IAsyncOperation<LampGetLampFaultsResult^>^ GetResultAsync(LampGetLampFaultsCalledEventArgs^ args)
    {
        args->InvokeAllFinished();
        auto t = concurrency::create_task(args->m_tce);
        return concurrency::create_async([t]() -> concurrency::task<LampGetLampFaultsResult^>
        {
            return t;
        });
    }
    
private:
    void Complete();
    void InvokeAllFinished();
    void InvokeCompleteHandler();

    bool m_raised;
    int m_completionsRequired;
    concurrency::task_completion_event<LampGetLampFaultsResult^> m_tce;
    std::mutex m_lock;
    Windows::Devices::AllJoyn::AllJoynMessageInfo^ m_messageInfo;
    LampGetLampFaultsResult^ m_result;
    Platform::String^ m_interfaceMemberLampID;
};

public ref class LampClearLampFaultCalledEventArgs sealed
{
public:
    LampClearLampFaultCalledEventArgs(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampID, _In_ uint32 interfaceMemberLampFault);

    property Windows::Devices::AllJoyn::AllJoynMessageInfo^ MessageInfo
    {
        Windows::Devices::AllJoyn::AllJoynMessageInfo^ get() { return m_messageInfo; }
    }

    property LampClearLampFaultResult^ Result
    {
        LampClearLampFaultResult^ get() { return m_result; }
        void set(_In_ LampClearLampFaultResult^ value) { m_result = value; }
    }

    property Platform::String^ LampID
    {
        Platform::String^ get() { return m_interfaceMemberLampID; }
    }

    property uint32 LampFault
    {
        uint32 get() { return m_interfaceMemberLampFault; }
    }

    Windows::Foundation::Deferral^ GetDeferral();

    static Windows::Foundation::IAsyncOperation<LampClearLampFaultResult^>^ GetResultAsync(LampClearLampFaultCalledEventArgs^ args)
    {
        args->InvokeAllFinished();
        auto t = concurrency::create_task(args->m_tce);
        return concurrency::create_async([t]() -> concurrency::task<LampClearLampFaultResult^>
        {
            return t;
        });
    }
    
private:
    void Complete();
    void InvokeAllFinished();
    void InvokeCompleteHandler();

    bool m_raised;
    int m_completionsRequired;
    concurrency::task_completion_event<LampClearLampFaultResult^> m_tce;
    std::mutex m_lock;
    Windows::Devices::AllJoyn::AllJoynMessageInfo^ m_messageInfo;
    LampClearLampFaultResult^ m_result;
    Platform::String^ m_interfaceMemberLampID;
    uint32 m_interfaceMemberLampFault;
};

public ref class LampGetLampServiceVersionCalledEventArgs sealed
{
public:
    LampGetLampServiceVersionCalledEventArgs(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberLampID);

    property Windows::Devices::AllJoyn::AllJoynMessageInfo^ MessageInfo
    {
        Windows::Devices::AllJoyn::AllJoynMessageInfo^ get() { return m_messageInfo; }
    }

    property LampGetLampServiceVersionResult^ Result
    {
        LampGetLampServiceVersionResult^ get() { return m_result; }
        void set(_In_ LampGetLampServiceVersionResult^ value) { m_result = value; }
    }

    property Platform::String^ LampID
    {
        Platform::String^ get() { return m_interfaceMemberLampID; }
    }

    Windows::Foundation::Deferral^ GetDeferral();

    static Windows::Foundation::IAsyncOperation<LampGetLampServiceVersionResult^>^ GetResultAsync(LampGetLampServiceVersionCalledEventArgs^ args)
    {
        args->InvokeAllFinished();
        auto t = concurrency::create_task(args->m_tce);
        return concurrency::create_async([t]() -> concurrency::task<LampGetLampServiceVersionResult^>
        {
            return t;
        });
    }
    
private:
    void Complete();
    void InvokeAllFinished();
    void InvokeCompleteHandler();

    bool m_raised;
    int m_completionsRequired;
    concurrency::task_completion_event<LampGetLampServiceVersionResult^> m_tce;
    std::mutex m_lock;
    Windows::Devices::AllJoyn::AllJoynMessageInfo^ m_messageInfo;
    LampGetLampServiceVersionResult^ m_result;
    Platform::String^ m_interfaceMemberLampID;
};

// Readable Properties
public ref class LampGetVersionRequestedEventArgs sealed
{
public:
    LampGetVersionRequestedEventArgs(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info);

    property Windows::Devices::AllJoyn::AllJoynMessageInfo^ MessageInfo
    {
        Windows::Devices::AllJoyn::AllJoynMessageInfo^ get() { return m_messageInfo; }
    }

    property LampGetVersionResult^ Result
    {
        LampGetVersionResult^ get() { return m_result; }
        void set(_In_ LampGetVersionResult^ value) { m_result = value; }
    }

    Windows::Foundation::Deferral^ GetDeferral();

    static Windows::Foundation::IAsyncOperation<LampGetVersionResult^>^ GetResultAsync(LampGetVersionRequestedEventArgs^ args)
    {
        args->InvokeAllFinished();
        auto t = concurrency::create_task(args->m_tce);
        return concurrency::create_async([t]() -> concurrency::task<LampGetVersionResult^>
        {
            return t;
        });
    }

private:
    void Complete();
    void InvokeAllFinished();
    void InvokeCompleteHandler();

    bool m_raised;
    int m_completionsRequired;
    concurrency::task_completion_event<LampGetVersionResult^> m_tce;
    std::mutex m_lock;
    Windows::Devices::AllJoyn::AllJoynMessageInfo^ m_messageInfo;
    LampGetVersionResult^ m_result;
};

// Writable Properties
} } } } } 