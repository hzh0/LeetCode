class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        sort(nums.begin(), nums.end());
        int res = nums[1]-nums[0];
        for (auto i = 2; i < nums.size(); ++i) res = max(res, nums[i]-nums[i-1]);
        return res;
    }
};