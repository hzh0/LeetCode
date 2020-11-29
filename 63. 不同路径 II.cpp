class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0;
        vector<vector<int>> v = obstacleGrid;
        v[0][0] = 1;
        int row = v.size(), col = v[0].size();
        for (auto j = 1; j < col; ++j)
            if (obstacleGrid[0][j] == 1 || v[0][j - 1] == 0) v[0][j] = 0;
            else v[0][j] = 1;
        for (auto i = 1; i < row; ++i)
            if (obstacleGrid[i][0] == 1 || v[i - 1][0] == 0) v[i][0] = 0;
            else v[i][0] = 1;
        for (auto i = 1; i < row; ++i) {
            for (auto j = 1; j < col; ++j) {
                if (obstacleGrid[i][j] == 1) v[i][j] = 0;
                else v[i][j] = v[i - 1][j] + v[i][j - 1];
            }
        }
        return v[row-1][col-1];
    }
};