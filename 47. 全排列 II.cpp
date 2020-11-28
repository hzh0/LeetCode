class Solution {
public:

    vector<int> tem;
    vector<vector<int>> ans;

    void dfs(bool* f, vector<int>& nums, int depth) {
        if (depth == nums.size()) ans.push_back(tem);
        else {
            for (auto i = 0; i < nums.size(); ++i) {
                if (f[i] || i > 0 && nums[i] == nums[i - 1] && !f[i-1]) continue;
                tem.push_back(nums[i]);
                f[i] = true;
                dfs(f, nums, depth + 1);
                f[i] = false;
                tem.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        bool* f = new bool[nums.size()]{ false };
        dfs(f, nums, 0);
        return ans;
    }
};