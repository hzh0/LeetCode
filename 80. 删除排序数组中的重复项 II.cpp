class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();
        int i = 2, j = 2;
        while (j < nums.size()) {
            if (nums[i] == nums[i-1] && nums[i] == nums[i-2] || nums[i-2] == nums[i-1] && nums[j] == nums[i-1]) {
                while (nums[i-1] == nums[j]) {
                    ++j;
                    if (j == nums.size()) return nums.size()-j+i;
                }
            }
            nums[i++] = nums[j++];
        }
        return nums.size()-j+i;
    }
};