class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int top = 0, bottom = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
        while (true) {
            for (auto i = left; i <= right; ++i) ans.push_back(matrix[top][i]);
            if (++top > bottom) break;
            for (auto i = top; i <= bottom; ++i) ans.push_back(matrix[i][right]);
            if (--right < left) break;
            for (auto i = right; i >= left; --i) ans.push_back(matrix[bottom][i]);
            if (--bottom < top) break;
            for (auto i = bottom; i >= top; --i) ans.push_back(matrix[i][left]);
            if (++left > right) break;
        }
        return ans;
    }
};