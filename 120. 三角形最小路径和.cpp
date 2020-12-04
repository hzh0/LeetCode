class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) return 0;
        if (triangle.size() == 1) return triangle[0][0];
        int n = triangle[triangle.size() - 1].size();
        vector<int> up(n, 0), down(n, 0);
        up[0] = triangle[0][0];
        for (auto i = 1; i < triangle.size(); ++i) {
            down[0] = up[0] + triangle[i][0];
            int size = triangle[i].size();
            for (auto j = 1; j < size-1; ++j) down[j] = min(up[j - 1], up[j]) + triangle[i][j];
            down[size-1] = up[size - 2] + triangle[i][size-1];
            up = down;
        }
        int ans = INT_MAX;
        for (auto i = 0; i < down.size(); ++i) ans = min(ans, down[i]);
        return ans;
    }
};