class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int row = A.size(), col = A[0].size();
        for (auto i = 0; i < row; ++i) {
            if (A[i][0] == 0) {
                for (auto j = 0; j < col; ++j) A[i][j] = 1 - A[i][j];
            }
        }
        for (auto j = 1; j < col; ++j) {
            int count = 0;
            for (auto i = 0; i < row; ++i) {
                if (A[i][j] == 1) count++;
            }
            if (count < row - count) {
                for (auto i = 0; i < row; ++i) A[i][j] = 1 - A[i][j];
            }
        }
        int ans = 0;
        for (auto i = 0; i < row; ++i) {
            for (auto j = 0; j < col; ++j) {
                if (A[i][j]) ans += pow(2, col - j - 1);
            }
        }
        return ans;
    }
};