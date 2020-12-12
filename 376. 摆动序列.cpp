class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int ans = 1, index;
        bool up = false;
        for (auto i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                index = i;
                up = nums[i] < nums[i - 1] ? true : false;
                break;
            }
        }
        for (auto i = index; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) {
                if (up) {
                    ans++;
                    up = false;
                }
            }
            else if (nums[i] > nums[i - 1]) {
                if (!up) {
                    ans++;
                    up = true;
                }
            }
        }
        return ans;
    }
};