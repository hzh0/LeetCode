class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int size = intervals.size();
        if (size <= 1) return 0;

        sort(intervals.begin(), intervals.end(), [](vector<int>& v1, vector<int>& v2) {
            if (v1[0] < v2[0]){
                return true;
            }
            if(v1[0] == v2[0]) {
                return v1[1] < v2[1];
            }
            return false;
        });

        int ans = 0;
        int cur = 0, next = 1;
        while (true) {
            if (intervals[cur][1] > intervals[next][0]) {
                ans++;  
                if (intervals[cur][1] > intervals[next][1]) {
                    cur = next;
                }           
            }
            else {
                cur = next;
            }
            next++;
            if (next == size) {
                return ans;
            }
        }
        return ans;
    }
};