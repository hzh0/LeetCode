class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) return 0;
        int size = timeSeries.size();
        int ans = 0;
        for (auto i = 1; i < size; ++i) {
            if (timeSeries[i]-timeSeries[i-1] < duration) ans += timeSeries[i]-timeSeries[i-1];
            else ans += duration;
        }
        ans += duration;
        return ans;
    }
};