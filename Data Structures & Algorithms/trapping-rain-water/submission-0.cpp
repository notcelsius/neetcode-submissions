class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;
        int l = 0;
        int r = height.size() - 1;
        int leftMax = height[l];
        int rightMax = height[r];
        while (l < r) {
            if (leftMax < rightMax) {
                l++;
                leftMax = max(leftMax, height[l]);
                water += leftMax - height[l];
            }
            else {
                r--;
                rightMax = max(rightMax, height[r]);
                water += rightMax - height[r];
            }
        }
        return water;
    }
};
