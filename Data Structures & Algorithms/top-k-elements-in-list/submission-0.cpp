class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int,int> buckets;
        vector<vector<int>> freq(nums.size() + 1);
        for (int num : nums) {
            buckets[num]++;
        }
        for (auto& pair : buckets) {
            freq[pair.second].push_back(pair.first);
        }
        for (int i = freq.size() - 1; i >= 0; i--) {
            for (int num : freq[i]) {
                result.push_back(num);
                if (result.size() == k) {
                    return result;
                }
            }
        }
        return result;


    }
};