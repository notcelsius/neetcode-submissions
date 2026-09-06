class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> diff;
        for (int i = 0; i < nums.size(); i++) {
            if (diff.find(nums[i]) != diff.end()) {
                return {diff[nums[i]], i};
            }
            diff[target-nums[i]] = i;
        }
        return {};
    }
};
