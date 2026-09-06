// Date Completed: 12/16/2024

// Leetcode Problem: https://leetcode.com/problems/container-with-most-water/description/

// Time Complexity: O(n)
// Space Complexity: O(1)

// using 2 ptrs method
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;  // will represent left side of container
        int r = height.size() - 1;  // will represent right side of container
        int area = 0;   // will represent maximum area of container
        while (l < r) { // squeeze
            area = max(area, (r-l) * min(height[l], height[r]));    // set area to be the max of current area and new area
            if (height[l] < height[r]) {    // if the height of left side is smaller than height of right side
                l++;    // we want to max area, keep the right side the same and change left side in hopes it will be larger
            }
            else {
                r--;    // right side was smaller, so find a new right side
            }
        }
        return area;    // returning the max area
    }
};