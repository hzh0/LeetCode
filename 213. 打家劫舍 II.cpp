class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        if (size == 1) return nums[0];
        if (size == 2) return max(nums[0], nums[1]);
        int first = 0, second = 0;
        int cur1, cur2;
        for (auto i = 0; i < size - 1; ++i) {
            cur1 = max(first + nums[i], second);
            first = second;
            second = cur1;
        }
        first = 0, second = 0;
        for (auto i = 1; i < size; ++i) {
            cur2 = max(first + nums[i], second);
            first = second;
            second = cur2;
        }
        return max(cur1, cur2);
    }
};