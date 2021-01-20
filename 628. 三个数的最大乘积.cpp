class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int num1 = nums[size-1]  * nums[size-2] * nums[size-3];
        int num2 = nums[size-1]  * nums[0] * nums[1];
        return num1 > num2 ? num1 : num2;
    }
};