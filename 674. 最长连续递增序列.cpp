class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int ans = 1;
        int tem = 1;
        for (auto i = 1; i < nums.size(); ++i) {
            if (nums[i]>nums[i-1]) tem++;
            else {
                ans = max(ans, tem);
                tem = 1;
            }
        }
        ans = max(ans, tem);
        return ans;
    }
};