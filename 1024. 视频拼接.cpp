// 动态规划方法
// dp[index] 为到位置 index 所需要的最少的片段数
// 对于一个区间[ai，bi)和位置index，若 ai < index <= bi ，则dp[index] = dp[ai] + 1
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        vector<int> dp(T+1, INT_MAX-1);
        dp[0] = 0;
        for (auto i = 1; i <= T; ++i) {
            for (auto it : clips) {
                if (it[0] < i && it[1] >= i) {
                    dp[i] = min(dp[i], dp[it[0]] + 1);
                }
            }
        }
        return dp[T] == INT_MAX-1 ? -1:dp[T];
    }
};

// 贪心算法
// 对片段进行排序
// 对任意一区间[ai,bi),每次都寻找能覆盖[0,bi)的，同时又能使bi最大的区间，以此来最大限度的减少所使用的区间数
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end());
        int size = clips.size();
        int curend = 0;
        int maxend = -1;
        int ans = 0;
        int index = 0;
        bool isfind;
        for (auto i : clips) {
            isfind = false;
            while (index < size && clips[index][0] <= curend) {
                isfind = true;
                if (clips[index][1] > curend) {
                    maxend = max(maxend,clips[index][1]);
                }
                index++;
            }
            if (isfind) {
                curend = maxend;
                ans++;
                if (curend >=T) return ans;
            } else {
                return -1;
            }
        }
        return -1;
    }
};