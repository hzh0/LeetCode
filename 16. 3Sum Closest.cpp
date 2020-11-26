class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        for (auto i = 0; i < nums.size() - 2; ++i) {
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int tsum = nums[i] + nums[left] + nums[right];
                if (tsum == target) return target;
                else if (tsum > target) right--;
                else if (tsum < target) left++;
                ans = abs(tsum - target) < abs(ans - target) ? tsum : ans;
            }
        }
        return ans;
    }
};