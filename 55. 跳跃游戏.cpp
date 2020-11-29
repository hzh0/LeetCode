class Solution {
public:
    bool canJump(vector<int>& nums) {
        int std = 1;
        for (int i = nums.size()-2; i >= 0; --i) {
            if (nums[i] < std) std++;
            else std=1;
        }
        return std == 1?true:false;
    }
};