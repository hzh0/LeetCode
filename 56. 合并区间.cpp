class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return intervals;
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), [](vector<int>& v1, vector<int>& v2) {
            return v1[0] < v2[0];
            }
        );

        ans.push_back(intervals[0]);
        intervals.erase(intervals.begin());

        for (auto& i : intervals) {
            if (ans[ans.size() - 1][1] >= i[0]) {
                if (i[1] > ans[ans.size() - 1][1])
                    ans[ans.size() - 1][1] = i[1];
            }
            else ans.push_back(i);
        }
        
        return ans;
    }
};