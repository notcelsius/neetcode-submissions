class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num: nums) {
            count[num]++;
        }
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto& [num, f]: count) {
            bucket[f].push_back(num);
        }
        vector<int> res;
        for (int i = bucket.size() - 1; i > 0 && res.size() < k; i--) {
            for (int num: bucket[i]) {
                res.push_back(num);
                if (res.size() == k) break;
            }
        }
        return res;
    }
};
