class Solution {
public:
    
    vector<int> tem;
    vector<vector<int>> ans;

    void dfs(vector<int>& nums, int index) {
        ans.push_back(tem);
        if (index == nums.size()) return;
        for (auto i = index; i < nums.size(); ++i) {
            if (i > index && nums[i] == nums[i - 1]) continue;
            tem.push_back(nums[i]);
            dfs(nums, i + 1);
            tem.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums,0);
        return ans;
    }
};