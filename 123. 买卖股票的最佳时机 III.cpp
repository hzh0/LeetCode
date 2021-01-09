class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1, sell1, buy2, sell2;
        buy1 = -prices[0], buy2 = -prices[0];
        sell1 = 0, sell2 = 0;
        for (auto i = 0; i < prices.size(); ++i) {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(buy1 + prices[i], sell1);
            buy2 = max(sell1-prices[i],buy2);
            sell2 = max(sell2, buy2+prices[i]);
        }
        return sell2;
    }
};