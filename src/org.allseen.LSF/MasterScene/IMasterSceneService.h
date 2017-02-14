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

namespace org { namespace allseen { namespace LSF { namespace ControllerService { namespace MasterScene {

public interface class IMasterSceneService
{
public:
    // Implement this function to handle calls to the GetAllMasterSceneIDs method.
    Windows::Foundation::IAsyncOperation<MasterSceneGetAllMasterSceneIDsResult^>^ GetAllMasterSceneIDsAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info );

    // Implement this function to handle calls to the GetMasterSceneName method.
    Windows::Foundation::IAsyncOperation<MasterSceneGetMasterSceneNameResult^>^ GetMasterSceneNameAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info , _In_ Platform::String^ interfaceMemberMasterSceneID, _In_ Platform::String^ interfaceMemberLanguage);

    // Implement this function to handle calls to the SetMasterSceneName method.
    Windows::Foundation::IAsyncOperation<MasterSceneSetMasterSceneNameResult^>^ SetMasterSceneNameAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info , _In_ Platform::String^ interfaceMemberMasterSceneID, _In_ Platform::String^ interfaceMemberMasterSceneName, _In_ Platform::String^ interfaceMemberLanguage);

    // Implement this function to handle calls to the CreateMasterScene method.
    Windows::Foundation::IAsyncOperation<MasterSceneCreateMasterSceneResult^>^ CreateMasterSceneAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info , _In_ Windows::Foundation::Collections::IVectorView<Platform::String^>^ interfaceMemberScenes, _In_ Platform::String^ interfaceMemberMasterSceneName, _In_ Platform::String^ interfaceMemberLanguage);

    // Implement this function to handle calls to the UpdateMasterScene method.
    Windows::Foundation::IAsyncOperation<MasterSceneUpdateMasterSceneResult^>^ UpdateMasterSceneAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info , _In_ Platform::String^ interfaceMemberMasterSceneID, _In_ Windows::Foundation::Collections::IVectorView<Platform::String^>^ interfaceMemberScenes);

    // Implement this function to handle calls to the DeleteMasterScene method.
    Windows::Foundation::IAsyncOperation<MasterSceneDeleteMasterSceneResult^>^ DeleteMasterSceneAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info , _In_ Platform::String^ interfaceMemberMasterSceneID);

    // Implement this function to handle calls to the GetMasterScene method.
    Windows::Foundation::IAsyncOperation<MasterSceneGetMasterSceneResult^>^ GetMasterSceneAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info , _In_ Platform::String^ interfaceMemberMasterSceneID);

    // Implement this function to handle calls to the ApplyMasterScene method.
    Windows::Foundation::IAsyncOperation<MasterSceneApplyMasterSceneResult^>^ ApplyMasterSceneAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info , _In_ Platform::String^ interfaceMemberMasterSceneID);

    // Implement this function to handle requests for the value of the Version property.
    //
    // Currently, info will always be null, because no information is available about the requestor.
    Windows::Foundation::IAsyncOperation<MasterSceneGetVersionResult^>^ GetVersionAsync(Windows::Devices::AllJoyn::AllJoynMessageInfo^ info);

};

} } } } } 
