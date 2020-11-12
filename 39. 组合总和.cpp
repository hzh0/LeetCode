class Solution {
public:

    vector<vector<int>> ans;

    void dfs(int& target, vector<int>& candidates, vector<int>& select, int index) {
        if (target < 0) return;
        if (target == 0) {
            ans.push_back(select);
            return;
        }
        for (auto i = index; i < candidates.size(); ++i) {
            select.push_back(candidates[i]);
            target = target - candidates[i];
            dfs(target, candidates, select, i);
            target = target + candidates[i];
            select.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> select;
        dfs(target, candidates, select, 0);
        return ans;
    }
};