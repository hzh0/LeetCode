class Solution {
public:

    void dfs(vector<vector<int>>& v, int i, int j) {
        if (i < 0 || i == v.size() || j < 0 || j == v[0].size()) {
            return;
        }
        if (v[i][j] == 0) {
            return;
        }
        else {
            v[i][j] = 0;
            dfs(v, i + 1, j);
            dfs(v, i - 1, j);
            dfs(v, i, j+1);
            dfs(v, i, j-1);
        }
    }

    int numEnclaves(vector<vector<int>>& A) {
        int ans = 0;
        int row = A.size(), col = A[0].size();
        for (auto i = 0; i < row; ++i) {
            if (A[i][0]) {
                dfs(A, i, 0);
            }
            if (A[i][col - 1]) {
                dfs(A, i, col-1);
            }
        }
        for (auto i = 1; i < col - 1; ++i) {
            if (A[0][i]) {
                dfs(A, 0, i);
            }
            if (A[row - 1][i]) {
                dfs(A, row - 1, i);
            }
        }
        for (auto& i : A) {
            for (auto& j : i) {
                if (j) {
                    ans++;
                }
            }
        }
        return ans;
    }
};