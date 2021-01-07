class Solution {
public:
    int ans = 0;
    
    void dfs(vector<vector<int>>& v, int row, vector<bool>& visted) {
        if (visted[row]) {
            return;
        }
        visted[row] = true;
        for (auto i = 0; i < v.size(); ++i) {
            if (v[row][i]) {
                dfs(v, i, visted);
            }   
        }  
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visted(n, false);
        for (auto i = 0; i < n; ++i) {
            if(!visted[i]) {
                dfs(isConnected, i, visted);
                ans++;
            }
        }
        return ans;
    }
};