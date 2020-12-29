class Solution {
public:
    
    int minPatches(vector<int>& nums, int n) {
        int res = 0;
        long long cur = 1;
        int left = 0;
        while (cur <= n) {
            if (left >= nums.size() || nums[left] > cur) {
                res++;
                cur += (cur - 1);
                cur++;  
            }
            else {
                cur += nums[left];
                left++;
            }
        }
        return res;
    }
};