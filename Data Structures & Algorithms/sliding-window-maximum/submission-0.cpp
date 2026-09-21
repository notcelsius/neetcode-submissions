class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        result.reserve(n - k + 1);

        deque<int> dq; // Stores indices

        for (int r = 0; r < n; r++) {
            // Remove indices whose values are smaller than nums[r].
            // They cannot be the maximum while nums[r] is in the window.
            while (!dq.empty() && nums[dq.back()] <= nums[r]) {
                dq.pop_back();
            }

            dq.push_back(r);

            // Remove the front index if it is outside the window [r-k+1, r].
            int left = r - k + 1;
            if (dq.front() < left) {
                dq.pop_front();
            }

            // The first complete window ends at index k - 1.
            if (r >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};