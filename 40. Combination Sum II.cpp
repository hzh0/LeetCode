class Solution {
public:
        
    vector<vector<int>> ans;
    set<vector<int>> s;
    vector<int> tem;

    void dfs(int depth, int index, vector<int>& v, int& target, int sum) {
        if (depth > v.size() || sum > target) return;
        if (sum == target) {
            vector<int> vt = tem;
            sort(vt.begin(), vt.end());
            s.insert(vt);
        }
        else {
            for (auto i = index + 1; i < v.size(); ++i) {
                tem.push_back(v[i]);
                sum += v[i];   
                dfs(depth + 1, i, v, target, sum);
                sum -= v[i];
                tem.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& v, int target) {
        dfs(0, -1, v, target, 0);
        for (auto it = s.begin(); it != s.end(); ++it) ans.push_back(*it);
        return ans;
    }
};