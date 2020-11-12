class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans(size,1);
        for (int i = 1; i < size; ++i) ans[i] = nums[i-1]*ans[i-1]; 
        int tem = 1;
        for (auto i = size-1; i >= 0; --i) {
            ans[i] *= tem;
            tem *= nums[i];
        }     
        return ans;
    }
};