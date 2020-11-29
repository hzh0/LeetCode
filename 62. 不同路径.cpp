class Solution {
public:
    int uniquePaths(int m, int n) {
        int** a = (int**)malloc(sizeof(int*) * n);
        for (auto i = 0; i < n; ++i) a[i] = (int*)malloc(sizeof(int) * m);
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < m; ++j) {
                if (i == 0 || j == 0) a[i][j] = 1;
                else a[i][j] = a[i - 1][j] + a[i][j - 1];
            }
        }
        return a[n - 1][m - 1];
    }
};