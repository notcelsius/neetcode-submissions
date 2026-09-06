// Date Completed: 12/16/2024

// Leetcode Problem: https://leetcode.com/problems/3sum/

// Time Complexity: O(n^2)
// Space Complexity: O(1) not accounting for result vector

// using 2 ptrs method
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result; // stores the triplets
        sort(nums.begin(), nums.end()); // sorting the num vector so can do 2 ptr method
        for (int i = 0; i < nums.size() - 2; i++) { // nums[i] will be target
                                                    // nums[j] + nums[k] == -nums[i]
            if (i > 0 && nums[i] == nums[i-1]) {    // need to unique triplets, so don't have multiple of the same target
                continue;
            }
            int j = i + 1;  // j will be at the left side
            int k = nums.size() - 1;    // k will be at the right side
            while (j < k) { // squeeze
                if (nums[j] + nums[k] == -nums[i]) {    // if it is a valid triplet
                    result.push_back({nums[i], nums[j], nums[k]});  // add it to result
                    // there could still be other unique triplets that add up to the target
                    j++;    // move j one to left
                    k--;    // move k one to right
                    while (j < k && nums[j] == nums[j-1]) { // mantain the squeeze while finding next unique j
                                                            // find unique j because then the triplet will be unique
                        j++;    // move j one to left
                    }
                }
                else if (nums[j] + nums[k] > -nums[i]) {    // combo of nums[j] + nums[k] too big, so need to decrease it
                    k--;    // decrease by moving k one left
                }
                else if (nums[j] + nums[k] < -nums[i]) {    // combo of nums[j] + nums[k] too small, so need to increase it
                    j++;    // increase by moving j one right
                }
            }
        }
        return result;  // return all unique triplets
    }
};