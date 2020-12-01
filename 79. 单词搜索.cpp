class Solution {
public:
    
    bool dfs(int depth, vector<vector<bool>>& vis, vector<vector<char>>& board, int i, int j, string& word) {
        if (depth == word.size()) return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false;
        if (vis[i][j]) return false;
        if (board[i][j] != word[depth]) return false;
        vis[i][j] = true;
        if (dfs(depth+1,vis,board,i+1,j,word)) return true;
        if (dfs(depth+1,vis,board,i-1,j,word)) return true;
        if (dfs(depth+1,vis,board,i,j+1,word)) return true;
        if (dfs(depth+1,vis,board,i,j-1,word)) return true;
        vis[i][j] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> v;
        for (auto i = 0; i < board.size(); ++i) {
            vector<bool> tem;
            for (auto j = 0; j < board[0].size(); ++j) tem.push_back(false);
            v.push_back(tem);
        }
        for (auto i = 0; i < board.size(); ++i) {
            for (auto j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0]) {
                    if (dfs(0,v,board,i,j,word)) return true;
                }
            }
        }
        return false;
    }
};