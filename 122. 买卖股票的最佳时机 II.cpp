class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int dp0 = 0, dp1 = -prices[0];
        for (auto& i : prices) {
            auto tem = dp0;
            dp0 = max(dp0,dp1 + i);
            dp1 = max(dp1, tem-i);
        }
        return dp0;
    }
};