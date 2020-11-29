class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        vector<vector<int>> ans;
        for (auto i = 0; i < n; ++i) {
            vector<int> tem;
            for (auto j = 0; j < n; ++j) tem.push_back(0);
            ans.push_back(tem);
        }
        int num = 1;
        while (num <= n*n) {
            for (auto i = left; i <= right; ++i) ans[top][i] = num++;
            ++top;
            for (auto i = top; i <= bottom; ++i) ans[i][right] = num++;
            --right;
            for (auto i = right; i >= left; --i) ans[bottom][i] = num++;  
            --bottom;
            for (auto i = bottom; i >= top; --i) ans[i][left] = num++;
            ++left;
        }
        return ans;
    }
};