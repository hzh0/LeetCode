class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans = 0;
        int size = ratings.size();
        vector<int> cd(size, 1);
        for (auto i = 1; i < size; ++i) {
            if (ratings[i] > ratings[i - 1]) cd[i] = cd[i-1]+1;
        }
        for (auto i = size - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1])
                cd[i] = max(cd[i + 1] + 1, cd[i]);
        }
        ans = accumulate(cd.begin(), cd.end(), 0);
        return ans;
    }
};