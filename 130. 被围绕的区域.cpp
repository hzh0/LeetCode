class Solution {
public:
    vector<vector<bool>> v;
    vector<vector<bool>> vis;
    int n, m;

    void dfs(int i, int j, vector<vector<char>>& board) {
        if (i < 0 || i == n || j < 0 || j == m) return;
        if (vis[i][j] == true) return;
        if (board[i][j] == 'O') {
            vis[i][j] = true;
            v[i][j] = true;
            dfs(i - 1, j, board);
            dfs(i + 1, j, board);
            dfs(i, j - 1, board);
            dfs(i, j + 1, board);
        }
        else return;

    }

    void solve(vector<vector<char>>& board) {
        if (!board.empty()) {
            n = board.size();
            m = board[0].size();
            
            for (auto i = 0; i < n; ++i) {
                vector<bool> tem;
                vector<bool> tem2;
                for (auto j = 0; j < m; ++j) {
                    if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && board[i][j] == 'O') tem.push_back(true);
                    else tem.push_back(false);
                    tem2.push_back(false);
                }
                v.push_back(tem);
                vis.push_back(tem2);
            }

            for (auto j = 0; j < m; ++j) {
                if (board[0][j] == 'O') dfs(0, j, board);
                if (board[n - 1][j] == 'O') dfs(n - 1, j, board);
            }
            for (auto i = 1; i < n - 1; ++i) {
                if (board[i][0] == 'O') dfs(i, 0, board);
                if (board[i][m - 1] == 'O') dfs(i, m - 1, board);
            }
            for (auto i = 0; i < n; ++i) {
                for (auto j = 0; j < m; ++j) {
                    if (v[i][j] == false && board[i][j] == 'O') board[i][j] = 'X';
                }
            }
        }
    }
};