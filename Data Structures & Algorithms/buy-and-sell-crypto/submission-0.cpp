class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int l = 0;
        int r = 0;
        while (r < prices.size()) {
            if (prices[r] < prices[l]) {
                l = r;
            }
            int profit = prices[r] - prices[l];
            maxProfit = max(profit, maxProfit);
            r++;
        }
        return maxProfit;
    }
};
