class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> index;
        index.push_back(-1);
        for (auto i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2) index.push_back(i); 
        }
        index.push_back(nums.size());
        if (index.size()-2 < k) return 0;
        int res = 0;
        for (auto i=1; i <= index.size()-2; ++i) {
            if (i + k-1 >= index.size()-1) return res;
            res += (index[i]-index[i-1])*(index[i+k]-index[i+k-1]);
        }
        return res;
    }
};