class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        int row = matrix.size(), col = matrix[0].size();
        for (auto i = 0; i < col; ++i) {
            vector<int> tem;
            for (auto j = 0; j < row; ++j) {
                tem.push_back(matrix[j][i]);
            }
            ans.push_back(tem);
        }
        return ans;
    }
};