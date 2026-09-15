class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size() - 2; k++) {
            if (k > 0 && nums[k] == nums[k-1]) {
                continue;
            }
            int target = -nums[k];
            int i = k+1;
            int j = nums.size() - 1;
            while (i < j) {
                if (nums[i] + nums[j] == target) {
                    res.push_back({nums[i],nums[j],nums[k]});
                    i++;
                    while (i < j && nums[i] == nums[i-1]) {
                        i++;
                    }
                    j--;
                    while (i < j && nums[j] == nums[j+1]) {
                        j--;
                    }
                    
                }
                else if (nums[i] + nums[j] < target) {
                    i++;
                }
                else {
                    j--;
                }
            }
        }
        return res;
    }
};