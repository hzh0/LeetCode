class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() == 2) return min(cost[0],cost[1]);
        int dp0 = 0, dp1 = 0;
        for (auto i = 2; i <= cost.size(); ++i) {
            int tem =dp1;
            dp1 = min(dp0+cost[i-2], dp1+cost[i-1]);
            dp0 = tem;
        }
        return dp1;
    }
};