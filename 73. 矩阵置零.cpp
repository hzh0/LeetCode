class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        bool rf = false, cf = false;
        for (auto j = 0; j < col; ++j) if (matrix[0][j] == 0) {rf=true;break;}
        for (auto i = 0; i < row; ++i) if (matrix[i][0] == 0) {cf = true; break;}
        for (auto i = 1; i < row; ++i) {
            for (auto j = 1; j < col; ++j) {
                if (matrix[i][j] == 0) matrix[i][0] = 0, matrix[0][j] = 0;
            }
        }        
        for (auto i = 1; i < row; ++i) {
            for (auto j = 1; j < col; ++j) {
                if (matrix[i][0] == 0) matrix[i][j] = 0;
                if (matrix[0][j] == 0) matrix[i][j] = 0;
            }
        } 
        if (rf) for (auto j = 0; j < col; ++j) matrix[0][j] = 0;
        if (cf) for (auto i = 0; i < row; ++i) matrix[i][0] = 0;
    }
};