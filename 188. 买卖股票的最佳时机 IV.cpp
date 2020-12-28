class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.empty()) return 0;
        int size = prices.size();
        if (k > size / 2) {
            int dp0 = 0, dp1 = -prices[0];
            for (auto& i : prices) {
                int tem = dp0;
                dp0 = max(dp0, dp1 + i);
                dp1 = max(tem - i, dp1);
            }
            return dp0;
        }
        else {
            int*** dp;
            dp = (int***)malloc(sizeof(int**) * size);
            for (auto i = 0; i < size; ++i) {
                dp[i] = (int**)malloc(sizeof(int*) * (k+1));
                for (auto j = 0; j <= k; ++j) {
                    dp[i][j] = (int*)malloc(sizeof(int) * 2);
                    dp[i][j][0] = 0;
                    dp[i][j][1] = 0;
                }
            }
            
            for (auto i = 0; i < size; ++i) {
                for (auto times = 1; times <= k; ++times) {
                    if (i == 0) {
                        dp[i][times][0] = 0;
                        dp[i][times][1] = -prices[0];
                        continue;
                    }
                    dp[i][times][0] = max(dp[i - 1][times][0], dp[i - 1][times][1] + prices[i]);
                    dp[i][times][1] = max(dp[i - 1][times][1], dp[i - 1][times - 1][0] - prices[i]);
                }
            }
            return dp[size - 1][k][0];
        }
    }
};