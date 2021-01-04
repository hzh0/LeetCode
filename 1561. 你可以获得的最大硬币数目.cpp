class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int ans = 0;
        int times = piles.size() / 3;
        int index = piles.size() - 2;
        for (auto i = 0; i < times; ++i) {
            ans += piles[index];
            index -= 2;
        }
        return ans;
    }
};