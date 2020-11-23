class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        int ans = 1;
        sort(points.begin(), points.end(), [](vector<int>& v1,vector<int>& v2){
            return v1[1] < v2[1];
        });
        int pre = points[0][1];
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > pre) {
                ans++;
                pre = points[i][1];
            }
        }
        return ans;
    }
};