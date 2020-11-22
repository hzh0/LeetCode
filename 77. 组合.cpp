class Solution {
public:
    
    vector<vector<int>> ans;
    vector<int> tem;

    void dfs(vector<bool>& flag, int k, int j) {
        if (tem.size() == k) ans.push_back(tem);
        else {
            for (auto i = j+1; i < flag.size(); ++i) {
                if (flag[i] == false) {
                    tem.push_back(i + 1);
                    flag[i] = true;
                    dfs(flag, k, i);
                    flag[i] = false;
                    tem.pop_back();
                }
            }
        }

    }

    vector<vector<int>> combine(int n, int k) {
        vector<bool> flag(n, false);
        dfs(flag, k, -1);
        return ans;
    }
};