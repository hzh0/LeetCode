class Solution {
public:
    vector<vector<string>> ans;
    vector<string> tem;
    vector<pair<int, int>> position;

    void gettem(vector<string>& tem, int n) {
        tem.clear();
        for (int i = 0; i < n; ++i) {
            string s = "";
            for (int j = 0; j < n; ++j) s += '.';
            tem.push_back(s);
        }
        for (auto i : position) tem[i.first][i.second] = 'Q';
    }

    bool confilic(vector<pair<int, int>>& position) {
        for (int i = 0; i < (int)position.size() - 1; ++i) {
            for (int j = i + 1; j < (int)position.size(); ++j) {
                if (position[i].second == position[j].second ||
                    abs(position[i].first - position[j].first) == abs(position[i].second - position[j].second))
                    return true;
            }
        }
        return false;
    }

    void dfs(int depth, int n) {
        if (confilic(position)) return;
        if (depth == n) {
            gettem(tem, n);
            ans.push_back(tem);
            return;
        }
        for (auto i = 0; i < n; ++i) {
            position.push_back(make_pair(depth, i));
            dfs(depth + 1, n);
            position.pop_back();
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        dfs(0, n);
        return ans;
    }
};