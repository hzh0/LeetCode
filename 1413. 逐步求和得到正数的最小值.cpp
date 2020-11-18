class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int num = nums[0];
        int ans = 0;
        for (auto i : nums) {
            ans += i;
            num = min(num, ans);
        }
        return 1-num >= 1 ? 1-num:1;
    }
};