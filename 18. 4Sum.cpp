class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        for (auto i = 0; i < nums.size() - 3; ++i) {
            for (auto j = i + 1; j < nums.size() - 2; ++j) {
                int left = j + 1, right = nums.size() - 1;
                while (left < right) {
                    int fsum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (fsum == target) {
                        s.insert({ nums[i], nums[j], nums[left], nums[right] });
                        left++;
                    }
                    else if (fsum > target) right--;
                    else left++;
                }
            }
        }
        vector<vector<int>> v;
        for (auto it = s.begin(); it != s.end(); it++) v.push_back(*it);
        return v;
    }
};