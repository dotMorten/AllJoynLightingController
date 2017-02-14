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

using namespace concurrency;
using namespace Microsoft::WRL;
using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::Devices::AllJoyn;
using namespace org::allseen::LSF::ControllerService::MasterScene;
namespace org { namespace allseen { namespace LSF { namespace ControllerService { namespace MasterScene {

// Methods
MasterSceneGetAllMasterSceneIDsCalledEventArgs::MasterSceneGetAllMasterSceneIDsCalledEventArgs(
    _In_ AllJoynMessageInfo^ info)
    : m_raised(false),
    m_completionsRequired(0),
    m_messageInfo(info)
{
    m_result = MasterSceneGetAllMasterSceneIDsResult::CreateFailureResult(ER_NOT_IMPLEMENTED);
}

Deferral^ MasterSceneGetAllMasterSceneIDsCalledEventArgs::GetDeferral()
{
    std::lock_guard<std::mutex> lockGuard(m_lock);
    if (m_raised)
    {
        // Cannot ask for a deferral after the event handler has returned.
        throw Exception::CreateException(E_ILLEGAL_METHOD_CALL);
    }

    m_completionsRequired++;
    auto handler = ref new DeferralCompletedHandler(this, &MasterSceneGetAllMasterSceneIDsCalledEventArgs::Complete);
    return ref new Deferral(handler);
}

void MasterSceneGetAllMasterSceneIDsCalledEventArgs::InvokeAllFinished()
{
    bool invokeNeeded;

    // We need to hold a lock while modifying private state, but release it before invoking a completion handler.
    {
        std::lock_guard<std::mutex> lockGuard(m_lock);
        m_raised = true;
        invokeNeeded = (m_completionsRequired == 0);
    }

    if (invokeNeeded)
    {
        InvokeCompleteHandler();
    }
}

void MasterSceneGetAllMasterSceneIDsCalledEventArgs::Complete()
{
    bool invokeNeeded;

    // We need to hold a lock while modifying private state, but release it before invoking a completion handler.
    {
        std::lock_guard<std::mutex> lockGuard(m_lock);
        if (m_completionsRequired == 0)
        {
            // This should never happen since Complete() should only be called by Windows.Foundation.Deferral
            // which will only invoke our completion handler once.
            throw Exception::CreateException(E_ILLEGAL_METHOD_CALL);
        }
        m_completionsRequired--;
        invokeNeeded = (m_raised && (m_completionsRequired == 0));
    }

    if (invokeNeeded)
    {
        InvokeCompleteHandler();
    }
}

void MasterSceneGetAllMasterSceneIDsCalledEventArgs::InvokeCompleteHandler()
{
    if (m_result->Status == ER_NOT_IMPLEMENTED)
    {
        throw Exception::CreateException(E_NOTIMPL, "No handlers are registered for GetAllMasterSceneIDsCalled.");
    }
    else
    {
        m_tce.set(m_result);
    }
}

MasterSceneGetMasterSceneNameCalledEventArgs::MasterSceneGetMasterSceneNameCalledEventArgs(
    _In_ AllJoynMessageInfo^ info,
    _In_ Platform::String^ interfaceMemberMasterSceneID,
    _In_ Platform::String^ interfaceMemberLanguage)
    : m_raised(false),
    m_completionsRequired(0),
    m_messageInfo(info),
    m_interfaceMemberMasterSceneID(interfaceMemberMasterSceneID),
    m_interfaceMemberLanguage(interfaceMemberLanguage)
{
    m_result = MasterSceneGetMasterSceneNameResult::CreateFailureResult(ER_NOT_IMPLEMENTED);
}

Deferral^ MasterSceneGetMasterSceneNameCalledEventArgs::GetDeferral()
{
    std::lock_guard<std::mutex> lockGuard(m_lock);
    if (m_raised)
    {
        // Cannot ask for a deferral after the event handler has returned.
        throw Exception::CreateException(E_ILLEGAL_METHOD_CALL);
    }

    m_completionsRequired++;
    auto handler = ref new DeferralCompletedHandler(this, &MasterSceneGetMasterSceneNameCalledEventArgs::Complete);
    return ref new Deferral(handler);
}

void MasterSceneGetMasterSceneNameCalledEventArgs::InvokeAllFinished()
{
    bool invokeNeeded;

    // We need to hold a lock while modifying private state, but release it before invoking a completion handler.
    {
        std::lock_guard<std::mutex> lockGuard(m_lock);
        m_raised = true;
        invokeNeeded = (m_completionsRequired == 0);
    }

    if (invokeNeeded)
    {
        InvokeCompleteHandler();
    }
}

void MasterSceneGetMasterSceneNameCalledEventArgs::Complete()
{
    bool invokeNeeded;

    // We need to hold a lock while modifying private state, but release it before invoking a completion handler.
    {
        std::lock_guard<std::mutex> lockGuard(m_lock);
        if (m_completionsRequired == 0)
        {
            // This should never happen since Complete() should only be called by Windows.Foundation.Deferral
            // which will only invoke our completion handler once.
            throw Exception::CreateException(E_ILLEGAL_METHOD_CALL);
        }
        m_completionsRequired--;
        invokeNeeded = (m_raised && (m_completionsRequired == 0));
    }

    if (invokeNeeded)
    {
        InvokeCompleteHandler();
    }
}

void MasterSceneGetMasterSceneNameCalledEventArgs::InvokeCompleteHandler()
{
    if (m_result->Status == ER_NOT_IMPLEMENTED)
    {
        throw Exception::CreateException(E_NOTIMPL, "No handlers are registered for GetMasterSceneNameCalled.");
    }
    else
    {
        m_tce.set(m_result);
    }
}

MasterSceneSetMasterSceneNameCalledEventArgs::MasterSceneSetMasterSceneNameCalledEventArgs(
    _In_ AllJoynMessageInfo^ info,
    _In_ Platform::String^ interfaceMemberMasterSceneID,
    _In_ Platform::String^ interfaceMemberMasterSceneName,
    _In_ Platform::String^ interfaceMemberLanguage)
    : m_raised(false),
    m_completionsRequired(0),
    m_messageInfo(info),
    m_interfaceMemberMasterSceneID(interfaceMemberMasterSceneID),
    m_interfaceMemberMasterSceneName(interfaceMemberMasterSceneName),
    m_interfaceMemberLanguage(interfaceMemberLanguage)
{
    m_result = MasterSceneSetMasterSceneNameResult::CreateFailureResult(ER_NOT_IMPLEMENTED);
}

Deferral^ MasterSceneSetMasterSceneNameCalledEventArgs::GetDeferral()
{
    std::lock_guard<std::mutex> lockGuard(m_lock);
    if (m_raised)
    {
        // Cannot ask for a deferral after the event handler has returned.
        throw Exception::CreateException(E_ILLEGAL_METHOD_CALL);
    }

    m_completionsRequired++;
    auto handler = ref new DeferralCompletedHandler(this, &MasterSceneSetMasterSceneNameCalledEventArgs::Complete);
    return ref new Deferral(handler);
}

void MasterSceneSetMasterSceneNameCalledEventArgs::InvokeAllFinished()
{
    bool invokeNeeded;

    // We need to hold a lock while modifying private state, but release it before invoking a completion handler.
    {
        std::lock_guard<std::mutex> lockGuard(m_lock);
        m_raised = true;
        invokeNeeded = (m_completionsRequired == 0);
    }

    if (invokeNeeded)
    {
        InvokeCompleteHandler();
    }
}

void MasterSceneSetMasterSceneNameCalledEventArgs::Complete()
{
    bool invokeNeeded;

    // We need to hold a lock while modifying private state, but release it before invoking a completion handler.
    {
        std::lock_guard<std::mutex> lockGuard(m_lock);
        if (m_completionsRequired == 0)
        {
            // This should never happen since Complete() should only be called by Windows.Foundation.Deferral
            // which will only invoke our completion handler once.
            throw Exception::CreateException(E_ILLEGAL_METHOD_CALL);
        }
        m_completionsRequired--;
        invokeNeeded = (m_raised && (m_completionsRequired == 0));
    }

    if (invokeNeeded)
    {
        InvokeCompleteHandler();
    }
}

void MasterSceneSetMasterSceneNameCalledEventArgs::InvokeCompleteHandler()
{
    if (m_result->Status == ER_NOT_IMPLEMENTED)
    {
        throw Exception::CreateException(E_NOTIMPL, "No handlers are registered for SetMasterSceneNameCalled.");
    }
    else
    {
        m_tce.set(m_result);
    }
}

MasterSceneCreateMasterSceneCalledEventArgs::MasterSceneCreateMasterSceneCalledEventArgs(
    _In_ AllJoynMessageInfo^ info,
    _In_ Windows::Foundation::Collections::IVectorView<Platform::String^>^ interfaceMemberScenes,
    _In_ Platform::String^ interfaceMemberMasterSceneName,
    _In_ Platform::String^ interfaceMemberLanguage)
    : m_raised(false),
    m_completionsRequired(0),
    m_messageInfo(info),
    m_interfaceMemberScenes(interfaceMemberScenes),
    m_interfaceMemberMasterSceneName(interfaceMemberMasterSceneName),
    m_interfaceMemberLanguage(interfaceMemberLanguage)
{
    m_result = MasterSceneCreateMasterSceneResult::CreateFailureResult(ER_NOT_IMPLEMENTED);
}

Deferral^ MasterSceneCreateMasterSceneCalledEventArgs::GetDeferral()
{
    std::lock_guard<std::mutex> lockGuard(m_lock);
    if (m_raised)
    {
        // Cannot ask for a deferral after the event handler has returned.
        throw Exception::CreateException(E_ILLEGAL_METHOD_CALL);
    }

    m_completionsRequired++;
    auto handler = ref new DeferralCompletedHandler(this, &MasterSceneCreateMasterSceneCalledEventArgs::Complete);
    return ref new Deferral(handler);
}

void MasterSceneCreateMasterSceneCalledEventArgs::InvokeAllFinished()
{
    bool invokeNeeded;

    // We need to hold a lock while modifying private state, but release it before invoking a completion handler.
    {
        std::lock_guard<std::mutex> lockGuard(m_lock);
        m_raised = true;
        invokeNeeded = (m_completionsRequired == 0);
    }

    if (invokeNeeded)
    {
        InvokeCompleteHandler();
    }
}

void MasterSceneCreateMasterSceneCalledEventArgs::Complete()
{
    bool invokeNeeded;

    // We need to hold a lock while modifying private state, but release it before invoking a completion handler.
    {
        std::lock_guard<std::mutex> lockGuard(m_lock);
        if (m_completionsRequired == 0)
        {
            // This should never happen since Complete() should only be called by Windows.Foundation.Deferral
            // which will only invoke our completion handler once.
            throw Exception::CreateException(E_ILLEGAL_METHOD_CALL);
        }
        m_completionsRequired--;
        invokeNeeded = (m_raised && (m_completionsRequired == 0));
    }

    if (invokeNeeded)
    {
        InvokeCompleteHandler();
    }
}

void MasterSceneCreateMasterSceneCalledEventArgs::InvokeCompleteHandler()
{
    if (m_result->Status == ER_NOT_IMPLEMENTED)
    {
        throw Exception::CreateException(E_NOTIMPL, "No handlers are registered for CreateMasterSceneCalled.");
    }
    else
    {
        m_tce.set(m_result);
    }
}

MasterSceneUpdateMasterSceneCalledEventArgs::MasterSceneUpdateMasterSceneCalledEventArgs(
    _In_ AllJoynMessageInfo^ info,
    _In_ Platform::String^ interfaceMemberMasterSceneID,
    _In_ Windows::Foundation::Collections::IVectorView<Platform::String^>^ interfaceMemberScenes)
    : m_raised(false),
    m_completionsRequired(0),
    m_messageInfo(info),
    m_interfaceMemberMasterSceneID(interfaceMemberMasterSceneID),
    m_interfaceMemberScenes(interfaceMemberScenes)
{
    m_result = MasterSceneUpdateMasterSceneResult::CreateFailureResult(ER_NOT_IMPLEMENTED);
}

Deferral^ MasterSceneUpdateMasterSceneCalledEventArgs::GetDeferral()
{
    std::lock_guard<std::mutex> lockGuard(m_lock);
    if (m_raised)
    {
        // Cannot ask for a deferral after the event handler has returned.
        throw Exception::CreateException(E_ILLEGAL_METHOD_CALL);
    }

    m_completionsRequired++;
    auto handler = ref new DeferralCompletedHandler(this, &MasterSceneUpdateMasterSceneCalledEventArgs::Complete);
    return ref new Deferral(handler);
}

void MasterSceneUpdateMasterSceneCalledEventArgs::InvokeAllFinished()
{
    bool invokeNeeded;

    // We need to hold a lock while modifying private state, but release it before invoking a completion handler.
    {
        std::lock_guard<std::mutex> lockGuard(m_lock);
        m_raised = true;
        invokeNeeded = (m_completionsRequired == 0);
    }

    if (invokeNeeded)
    {
        InvokeCompleteHandler();
    }
}

void MasterSceneUpdateMasterSceneCalledEventArgs::Complete()
{
    bool invokeNeeded;

    // We need to hold a lock while modifying private state, but release it before invoking a completion handler.
    {
        std::lock_guard<std::mutex> lockGuard(m_lock);
        if (m_completionsRequired == 0)
        {
            // This should never happen since Complete() should only be called by Windows.Foundation.Deferral
            // which will only invoke our completion handler once.
            throw Exception::CreateException(E_ILLEGAL_METHOD_CALL);
        }
        m_completionsRequired--;
        invokeNeeded = (m_raised && (m_completionsRequired == 0));
    }

    if (invokeNeeded)
    {
        InvokeCompleteHandler();
    }
}

void MasterSceneUpdateMasterSceneCalledEventArgs::InvokeCompleteHandler()
{
    if (m_result->Status == ER_NOT_IMPLEMENTED)
    {
        throw Exception::CreateException(E_NOTIMPL, "No handlers are registered for UpdateMasterSceneCalled.");
    }
    else
    {
        m_tce.set(m_result);
    }
}

MasterSceneDeleteMasterSceneCalledEventArgs::MasterSceneDeleteMasterSceneCalledEventArgs(
    _In_ AllJoynMessageInfo^ info,
    _In_ Platform::String^ interfaceMemberMasterSceneID)
    : m_raised(false),
    m_completionsRequired(0),
    m_messageInfo(info),
    m_interfaceMemberMasterSceneID(interfaceMemberMasterSceneID)
{
    m_result = MasterSceneDeleteMasterSceneResult::CreateFailureResult(ER_NOT_IMPLEMENTED);
}

Deferral^ MasterSceneDeleteMasterSceneCalledEventArgs::GetDeferral()
{
    std::lock_guard<std::mutex> lockGuard(m_lock);
    if (m_raised)
    {
        // Cannot ask for a deferral after the event handler has returned.
        throw Exception::CreateException(E_ILLEGAL_METHOD_CALL);
    }

    m_completionsRequired++;
    auto handler = ref new DeferralCompletedHandler(this, &MasterSceneDeleteMasterSceneCalledEventArgs::Complete);
    return ref new Deferral(handler);
}

void MasterSceneDeleteMasterSceneCalledEventArgs::InvokeAllFinished()
{
    bool invokeNeeded;

    // We need to hold a lock while modifying private state, but release it before invoking a completion handler.
    {
        std::lock_guard<std::mutex> lockGuard(m_lock);
        m_raised = true;
        invokeNeeded = (m_completionsRequired == 0);
    }

    if (invokeNeeded)
    {
        InvokeCompleteHandler();
    }
}

void MasterSceneDeleteMasterSceneCalledEventArgs::Complete()
{
    bool invokeNeeded;

    // We need to hold a lock while modifying private state, but release it before invoking a completion handler.
    {
        std::lock_guard<std::mutex> lockGuard(m_lock);
        if (m_completionsRequired == 0)
        {
            // This should never happen since Complete() should only be called by Windows.Foundation.Deferral
            // which will only invoke our completion handler once.
            throw Exception::CreateException(E_ILLEGAL_METHOD_CALL);
        }
        m_completionsRequired--;
        invokeNeeded = (m_raised && (m_completionsRequired == 0));
    }

    if (invokeNeeded)
    {
        InvokeCompleteHandler();
    }
}

void MasterSceneDeleteMasterSceneCalledEventArgs::InvokeCompleteHandler()
{
    if (m_result->Status == ER_NOT_IMPLEMENTED)
    {
        throw Exception::CreateException(E_NOTIMPL, "No handlers are registered for DeleteMasterSceneCalled.");
    }
    else
    {
        m_tce.set(m_result);
    }
}

MasterSceneGetMasterSceneCalledEventArgs::MasterSceneGetMasterSceneCalledEventArgs(
    _In_ AllJoynMessageInfo^ info,
    _In_ Platform::String^ interfaceMemberMasterSceneID)
    : m_raised(false),
    m_completionsRequired(0),
    m_messageInfo(info),
    m_interfaceMemberMasterSceneID(interfaceMemberMasterSceneID)
{
    m_result = MasterSceneGetMasterSceneResult::CreateFailureResult(ER_NOT_IMPLEMENTED);
}

Deferral^ MasterSceneGetMasterSceneCalledEventArgs::GetDeferral()
{
    std::lock_guard<std::mutex> lockGuard(m_lock);
    if (m_raised)
    {
        // Cannot ask for a deferral after the event handler has returned.
        throw Exception::CreateException(E_ILLEGAL_METHOD_CALL);
    }

    m_completionsRequired++;
    auto handler = ref new DeferralCompletedHandler(this, &MasterSceneGetMasterSceneCalledEventArgs::Complete);
    return ref new Deferral(handler);
}

void MasterSceneGetMasterSceneCalledEventArgs::InvokeAllFinished()
{
    bool invokeNeeded;

    // We need to hold a lock while modifying private state, but release it before invoking a completion handler.
    {
        std::lock_guard<std::mutex> lockGuard(m_lock);
        m_raised = true;
        invokeNeeded = (m_completionsRequired == 0);
    }

    if (invokeNeeded)
    {
        InvokeCompleteHandler();
    }
}

void MasterSceneGetMasterSceneCalledEventArgs::Complete()
{
    bool invokeNeeded;

    // We need to hold a lock while modifying private state, but release it before invoking a completion handler.
    {
        std::lock_guard<std::mutex> lockGuard(m_lock);
        if (m_completionsRequired == 0)
        {
            // This should never happen since Complete() should only be called by Windows.Foundation.Deferral
            // which will only invoke our completion handler once.
            throw Exception::CreateException(E_ILLEGAL_METHOD_CALL);
        }
        m_completionsRequired--;
        invokeNeeded = (m_raised && (m_completionsRequired == 0));
    }

    if (invokeNeeded)
    {
        InvokeCompleteHandler();
    }
}

void MasterSceneGetMasterSceneCalledEventArgs::InvokeCompleteHandler()
{
    if (m_result->Status == ER_NOT_IMPLEMENTED)
    {
        throw Exception::CreateException(E_NOTIMPL, "No handlers are registered for GetMasterSceneCalled.");
    }
    else
    {
        m_tce.set(m_result);
    }
}

MasterSceneApplyMasterSceneCalledEventArgs::MasterSceneApplyMasterSceneCalledEventArgs(
    _In_ AllJoynMessageInfo^ info,
    _In_ Platform::String^ interfaceMemberMasterSceneID)
    : m_raised(false),
    m_completionsRequired(0),
    m_messageInfo(info),
    m_interfaceMemberMasterSceneID(interfaceMemberMasterSceneID)
{
    m_result = MasterSceneApplyMasterSceneResult::CreateFailureResult(ER_NOT_IMPLEMENTED);
}

Deferral^ MasterSceneApplyMasterSceneCalledEventArgs::GetDeferral()
{
    std::lock_guard<std::mutex> lockGuard(m_lock);
    if (m_raised)
    {
        // Cannot ask for a deferral after the event handler has returned.
        throw Exception::CreateException(E_ILLEGAL_METHOD_CALL);
    }

    m_completionsRequired++;
    auto handler = ref new DeferralCompletedHandler(this, &MasterSceneApplyMasterSceneCalledEventArgs::Complete);
    return ref new Deferral(handler);
}

void MasterSceneApplyMasterSceneCalledEventArgs::InvokeAllFinished()
{
    bool invokeNeeded;

    // We need to hold a lock while modifying private state, but release it before invoking a completion handler.
    {
        std::lock_guard<std::mutex> lockGuard(m_lock);
        m_raised = true;
        invokeNeeded = (m_completionsRequired == 0);
    }

    if (invokeNeeded)
    {
        InvokeCompleteHandler();
    }
}

void MasterSceneApplyMasterSceneCalledEventArgs::Complete()
{
    bool invokeNeeded;

    // We need to hold a lock while modifying private state, but release it before invoking a completion handler.
    {
        std::lock_guard<std::mutex> lockGuard(m_lock);
        if (m_completionsRequired == 0)
        {
            // This should never happen since Complete() should only be called by Windows.Foundation.Deferral
            // which will only invoke our completion handler once.
            throw Exception::CreateException(E_ILLEGAL_METHOD_CALL);
        }
        m_completionsRequired--;
        invokeNeeded = (m_raised && (m_completionsRequired == 0));
    }

    if (invokeNeeded)
    {
        InvokeCompleteHandler();
    }
}

void MasterSceneApplyMasterSceneCalledEventArgs::InvokeCompleteHandler()
{
    if (m_result->Status == ER_NOT_IMPLEMENTED)
    {
        throw Exception::CreateException(E_NOTIMPL, "No handlers are registered for ApplyMasterSceneCalled.");
    }
    else
    {
        m_tce.set(m_result);
    }
}

// Readable Properties
MasterSceneGetVersionRequestedEventArgs::MasterSceneGetVersionRequestedEventArgs(
    _In_ AllJoynMessageInfo^ info)
    : m_raised(false),
    m_completionsRequired(0),
    m_messageInfo(info)
{
    m_result = MasterSceneGetVersionResult::CreateFailureResult(ER_NOT_IMPLEMENTED);
}

Deferral^ MasterSceneGetVersionRequestedEventArgs::GetDeferral()
{
    std::lock_guard<std::mutex> lockGuard(m_lock);
    if (m_raised)
    {
        // Cannot ask for a deferral after the event handler has returned.
        throw Exception::CreateException(E_ILLEGAL_METHOD_CALL);
    }

    m_completionsRequired++;
    auto handler = ref new DeferralCompletedHandler(this, &MasterSceneGetVersionRequestedEventArgs::Complete);
    return ref new Deferral(handler);
}

void MasterSceneGetVersionRequestedEventArgs::InvokeAllFinished()
{
    bool invokeNeeded;

    // We need to hold a lock while modifying private state, but release it before invoking a completion handler.
    {
        std::lock_guard<std::mutex> lockGuard(m_lock);
        m_raised = true;
        invokeNeeded = (m_completionsRequired == 0);
    }

    if (invokeNeeded)
    {
        InvokeCompleteHandler();
    }
}

void MasterSceneGetVersionRequestedEventArgs::Complete()
{
    bool invokeNeeded;

    // We need to hold a lock while modifying private state, but release it before invoking a completion handler.
    {
        std::lock_guard<std::mutex> lockGuard(m_lock);
        if (m_completionsRequired == 0)
        {
            // This should never happen since Complete() should only be called by Windows.Foundation.Deferral
            // which will only invoke our completion handler once.
            throw Exception::CreateException(E_ILLEGAL_METHOD_CALL);
        }
        m_completionsRequired--;
        invokeNeeded = (m_raised && (m_completionsRequired == 0));
    }

    if (invokeNeeded)
    {
        InvokeCompleteHandler();
    }
}

void MasterSceneGetVersionRequestedEventArgs::InvokeCompleteHandler()
{
    if (m_result->Status == ER_NOT_IMPLEMENTED)
    {
        throw Exception::CreateException(E_NOTIMPL, "No handlers are registered for GetVersionRequested.");
    }
    else
    {
        m_tce.set(m_result);
    }
}

// Writable Properties
} } } } } 
