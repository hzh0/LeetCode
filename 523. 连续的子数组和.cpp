class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector <int> v;
        for (auto i = 0; i < n; ++i) {
            for (auto j = i; j < n; ++j) {
                if (i == j) {
                    v.push_back(nums[i]);
                }
                else {
                    if (k == 0) {
                        if (nums[j] + v[v.size() - 1] == 0) return true;
                    }
                    else if ((nums[j] + v[v.size() - 1]) % k == 0) return true;
                    v.push_back(nums[j] + v[v.size() - 1]);
                }
            }
        }
        return false;
    }
};