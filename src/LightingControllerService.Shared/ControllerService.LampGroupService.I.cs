using System;
using org.allseen.LSF.ControllerService;
using Windows.Devices.AllJoyn;
using Windows.Foundation;
using System.Threading.Tasks;
using org.allseen.LSF.ControllerService.LampGroup;
using System.Collections.Generic;
using Windows.Storage;
using System.Text;

namespace LightingControllerService
{
    internal partial class ControllerService : ILampGroupService
    {
        private Dictionary<string, LampGroup> lampGroups = new Dictionary<string, LampGroup>();
        private void SaveLampGroups()
        {
            var container = Windows.Storage.ApplicationData.Current.LocalSettings.CreateContainer("LampGroups", Windows.Storage.ApplicationDataCreateDisposition.Always);
            container.Values.Clear();
            foreach(var group in lampGroups)
            {
                container.Values[group.Key] = group.Value.Serialize();
            }
        }
        private void LoadLampGroups()
        {
            var container = Windows.Storage.ApplicationData.Current.LocalSettings.CreateContainer("LampGroups", Windows.Storage.ApplicationDataCreateDisposition.Always);
            foreach (var group in container.Values)
            {
                lampGroups[group.Key] = LampGroup.FromString((string)group.Value);
            }
        }

        private class LampGroup
        {
            public LampGroup(string name, string language, IEnumerable<string> lampIds, IEnumerable<string> lampGroupIDs)
                : this(new KeyValuePair<string,string>[] { new KeyValuePair<string, string>(language, name) }, lampIds, lampGroupIDs)
            {
            }
            public LampGroup(IEnumerable<KeyValuePair<string,string>> names, IEnumerable<string> lampIds, IEnumerable<string> lampGroupIDs)
            {
                foreach (var lang in names)
                    GroupName[lang.Key] = lang.Value;
                LampIds = new List<string>(lampIds);
                LampGroupIds = new List<string>(lampGroupIDs);
            }

            public Dictionary<string, string> GroupName { get; } = new Dictionary<string, string>();
            public List<string> LampIds { get; set; }
            public List<string> LampGroupIds { get; set; }
            public string Serialize()
            {
                //TODO: Use JSON serialization
                StringBuilder sb = new StringBuilder();
                foreach(var l in GroupName)
                    sb.Append($"{l.Key}={l.Value}\t");
                sb.Append("\n");
                sb.Append(string.Join("\t", LampIds));
                sb.Append("\n");
                sb.Append(string.Join("\t", LampGroupIds));
                return sb.ToString();
            }
            public static LampGroup FromString(string str)
            {
                //TODO: Use JSON serialization
                string[] lines = str.Split(new char[] { '\n' });
                var languages = lines[0].Split(new char[] { '\t' }, StringSplitOptions.RemoveEmptyEntries);
                Dictionary<string, string> names = new Dictionary<string, string>();
                foreach(var item in languages)
                {
                    var lang = item.Split(new char[] { '=' });
                    names[lang[0]] = lang[1];
                }
                var lampIds = lines[1].Split(new char[] { '\t' }, StringSplitOptions.RemoveEmptyEntries);
                var lampGroupIds = lines[1].Split(new char[] { '\t' }, StringSplitOptions.RemoveEmptyEntries);
                return new LampGroup(names, lampIds, lampGroupIds);
            }
        }

        IAsyncOperation<LampGroupCreateLampGroupResult> ILampGroupService.CreateLampGroupAsync(AllJoynMessageInfo info, 
            IReadOnlyList<string> lampIDs, IReadOnlyList<string> lampGroupIDs, string lampGroupName, string language)
        {
            if (string.IsNullOrEmpty(lampGroupName))
                return Task.FromResult(LampGroupCreateLampGroupResult.CreateFailureResult(12)).AsAsyncOperation(); //Name was empty

            if (lampIDs == null || lampGroupIDs == null || string.IsNullOrWhiteSpace(language))
                return Task.FromResult(LampGroupCreateLampGroupResult.CreateFailureResult(11)).AsAsyncOperation(); //Invalid arguments

            string groupID = Guid.NewGuid().ToString();

            LampGroup group = new LampGroup(lampGroupName, language, lampIDs, lampGroupIDs);
            lampGroups.Add(groupID, group);
            LampGroupProducer.Signals.LampGroupsCreated(new List<string>() { groupID }.AsReadOnly());

            SaveLampGroups();

            return Task.FromResult(LampGroupCreateLampGroupResult.CreateSuccessResult(0, groupID)).AsAsyncOperation();
        }

        IAsyncOperation<LampGroupDeleteLampGroupResult> ILampGroupService.DeleteLampGroupAsync(AllJoynMessageInfo info, string lampGroupID)
        {
            if (!lampGroups.ContainsKey(lampGroupID))
                return Task.FromResult(LampGroupDeleteLampGroupResult.CreateFailureResult(16)).AsAsyncOperation();
            lampGroups.Remove(lampGroupID);
            LampGroupProducer.Signals.LampGroupsDeleted(new List<string> { lampGroupID });
            return Task.FromResult(LampGroupDeleteLampGroupResult.CreateSuccessResult(0, lampGroupID)).AsAsyncOperation();
        }

        IAsyncOperation<LampGroupGetAllLampGroupIDsResult> ILampGroupService.GetAllLampGroupIDsAsync(AllJoynMessageInfo info)
        {
            return Task.FromResult(LampGroupGetAllLampGroupIDsResult.CreateSuccessResult(0, new List<string>(lampGroups.Keys))).AsAsyncOperation();
        }

        IAsyncOperation<LampGroupGetLampGroupResult> ILampGroupService.GetLampGroupAsync(AllJoynMessageInfo info, string lampGroupID)
        {
            if (!lampGroups.ContainsKey(lampGroupID))
                return Task.FromResult(LampGroupGetLampGroupResult.CreateFailureResult(16)).AsAsyncOperation();
            var group = lampGroups[lampGroupID];
            return Task.FromResult(LampGroupGetLampGroupResult.CreateSuccessResult(0, lampGroupID, group.LampIds, group.LampGroupIds)).AsAsyncOperation();
        }

        IAsyncOperation<LampGroupGetLampGroupNameResult> ILampGroupService.GetLampGroupNameAsync(AllJoynMessageInfo info, string lampGroupID, string language)
        {
            if (!lampGroups.ContainsKey(lampGroupID))
                return Task.FromResult(LampGroupGetLampGroupNameResult.CreateFailureResult(16)).AsAsyncOperation();
            var group = lampGroups[lampGroupID];

            if (group.GroupName.ContainsKey(language))
                return Task.FromResult(LampGroupGetLampGroupNameResult.CreateSuccessResult(0, lampGroupID, language, group.GroupName[language])).AsAsyncOperation();
            return Task.FromResult(LampGroupGetLampGroupNameResult.CreateFailureResult(16)).AsAsyncOperation();
        }

        IAsyncOperation<LampGroupGetVersionResult> ILampGroupService.GetVersionAsync(AllJoynMessageInfo info)
        {
            return Task.FromResult(LampGroupGetVersionResult.CreateSuccessResult(InterfaceVersion)).AsAsyncOperation();
        }

        IAsyncOperation<LampGroupSetLampGroupNameResult> ILampGroupService.SetLampGroupNameAsync(AllJoynMessageInfo info, string lampGroupID, string LampGroupName, string Language)
        {
            if (!lampGroups.ContainsKey(lampGroupID))
                return Task.FromResult(LampGroupSetLampGroupNameResult.CreateFailureResult(16)).AsAsyncOperation();
            if (string.IsNullOrEmpty(LampGroupName))
                return Task.FromResult(LampGroupSetLampGroupNameResult.CreateFailureResult(12)).AsAsyncOperation();
            if (string.IsNullOrEmpty(Language))
                return Task.FromResult(LampGroupSetLampGroupNameResult.CreateFailureResult(5)).AsAsyncOperation();
            var group = lampGroups[lampGroupID];
            group.GroupName[Language] = LampGroupName;
            LampGroupProducer.Signals.LampGroupsNameChanged(new List<string>() { lampGroupID }.AsReadOnly());
            return Task.FromResult(LampGroupSetLampGroupNameResult.CreateSuccessResult(0, lampGroupID, Language)).AsAsyncOperation();
        }

        IAsyncOperation<LampGroupUpdateLampGroupResult> ILampGroupService.UpdateLampGroupAsync(AllJoynMessageInfo info, string lampGroupID, IReadOnlyList<string> LampIDs, IReadOnlyList<string> lampGroupIDs)
        {
            if (!lampGroups.ContainsKey(lampGroupID))
                return Task.FromResult(LampGroupUpdateLampGroupResult.CreateFailureResult(16)).AsAsyncOperation();
            var lampGroup = lampGroups[lampGroupID];
            lampGroup.LampGroupIds = new List<string>(lampGroupIDs);
            lampGroup.LampIds = new List<string>(LampIDs);
            LampGroupProducer.Signals.LampGroupsUpdated(new List<string> { lampGroupID });

            return Task.FromResult(LampGroupUpdateLampGroupResult.CreateSuccessResult(0, lampGroupID)).AsAsyncOperation();
        }

        IAsyncOperation<LampGroupResetLampGroupStateFieldResult> ILampGroupService.ResetLampGroupStateFieldAsync(AllJoynMessageInfo info, string lampGroupID, string LampGroupStateFieldName)
        {
            //TODO
            return Task.FromResult(LampGroupResetLampGroupStateFieldResult.CreateFailureResult(7)).AsAsyncOperation();
        }

        IAsyncOperation<LampGroupPulseLampGroupWithPresetResult> ILampGroupService.PulseLampGroupWithPresetAsync(AllJoynMessageInfo info, string lampGroupID, string FromPresetID, string ToPresetID, uint Period, uint Duration, uint NumPulses)
        {
            //TODO
            return Task.FromResult(LampGroupPulseLampGroupWithPresetResult.CreateFailureResult(7)).AsAsyncOperation();
        }

        IAsyncOperation<LampGroupPulseLampGroupWithStateResult> ILampGroupService.PulseLampGroupWithStateAsync(AllJoynMessageInfo info, string lampGroupID, IReadOnlyDictionary<string, object> FromLampGroupState, IReadOnlyDictionary<string, object> ToLampGroupState, uint Period, uint Duration, uint NumPulses)
        {
            //TODO
            return Task.FromResult(LampGroupPulseLampGroupWithStateResult.CreateFailureResult(7)).AsAsyncOperation();
        }

        IAsyncOperation<LampGroupResetLampGroupStateResult> ILampGroupService.ResetLampGroupStateAsync(AllJoynMessageInfo info, string lampGroupID)
        {
            //TODO
            return Task.FromResult(LampGroupResetLampGroupStateResult.CreateFailureResult(7)).AsAsyncOperation();
        }

        IAsyncOperation<LampGroupTransitionLampGroupStateResult> ILampGroupService.TransitionLampGroupStateAsync(AllJoynMessageInfo info, string lampGroupID, IReadOnlyDictionary<string, object> LampState, uint TransitionPeriod)
        {
            //TODO
            return Task.FromResult(LampGroupTransitionLampGroupStateResult.CreateFailureResult(7)).AsAsyncOperation();
        }

        IAsyncOperation<LampGroupTransitionLampGroupStateFieldResult> ILampGroupService.TransitionLampGroupStateFieldAsync(AllJoynMessageInfo info, string lampGroupID, string LampGroupStateFieldName, object LampGroupStateFieldValue, uint TransitionPeriod)
        {
            //TODO
            return Task.FromResult(LampGroupTransitionLampGroupStateFieldResult.CreateFailureResult(7)).AsAsyncOperation();
        }

        IAsyncOperation<LampGroupTransitionLampGroupStateToPresetResult> ILampGroupService.TransitionLampGroupStateToPresetAsync(AllJoynMessageInfo info, string lampGroupID, string PresetID, uint TransitionPeriod)
        {
            //TODO
            return Task.FromResult(LampGroupTransitionLampGroupStateToPresetResult.CreateFailureResult(7)).AsAsyncOperation();
        }
    }
}