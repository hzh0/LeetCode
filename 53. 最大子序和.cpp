class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return -2147483648;
        if (nums.size() == 1) return nums[0];
        int f0 = nums[0], f1 = max(nums[1]+f0, nums[1]);
        int ans = max(f0,f1);
        for (auto i = 2; i< nums.size(); ++i) {
            f0 = f1;
            f1 = max(nums[i]+f0, nums[i]);
            ans = max(ans, f1);
        }
        return ans;
    }
};