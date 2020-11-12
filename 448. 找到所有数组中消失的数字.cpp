class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (auto i = 0; i < nums.size(); ++i) nums[abs(nums[i])-1] = -abs(nums[abs(nums[i])-1]);
        vector<int> v;
        for (auto i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) v.push_back(i+1);
        }
        return v;
    }
};