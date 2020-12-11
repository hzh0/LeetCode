class Solution {
public:

    vector<vector<bool>> vis;
    int ans = 0;

    void dfs(int i, int j, int& tarnum, int cur, int* fn) {
        if (i < 0 || i >= vis.size() || j < 0 || j >= vis[0].size() || vis[i][j] == true) return;
        if (i == fn[0] && j == fn[1] && cur == tarnum) ans++;
        else {
            vis[i][j] = true;
            cur++;
            dfs(i + 1, j, tarnum, cur, fn);
            dfs(i - 1, j, tarnum, cur, fn);
            dfs(i, j+1, tarnum, cur, fn);
            dfs(i, j-1, tarnum, cur, fn);
            cur--;
            vis[i][j] = false;
        }
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int tarnum = 1, row = grid.size(), col = grid[0].size();
        int st[2], fn[2];
        for (auto i = 0; i < row; ++i) {
            vector<bool> tem(col, true);
            for (auto j = 0; j < col; ++j)
                if (grid[i][j] == 0) tem[j] = false, tarnum++;
                else if (grid[i][j] == 1) st[0] = i, st[1] = j, tem[j] = false;
                else if (grid[i][j] == 2) fn[0] = i, fn[1] = j, tem[j] = false;
            vis.push_back(tem);
        }
        dfs(st[0], st[1], tarnum, 0, fn);
        return ans;
    }
};