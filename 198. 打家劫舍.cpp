class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        vector<int> v(nums.size(),0);
        int re = -1;
        v[0] = nums[0];
        re = max(re, v[0]);
        for (auto i =1; i < nums.size(); ++i) {
            if (i-2 >= 0) v[i] = max(nums[i]+v[i-2],v[i-1]);
            else v[i] = max(nums[i],v[i-1]);
            re = max(re, v[i]);
        }
        return re;
    }
};