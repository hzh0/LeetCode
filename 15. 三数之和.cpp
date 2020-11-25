class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return {};
        set<vector<int>> ans;
        vector<vector<int>> v;
        sort(nums.begin(), nums.end());
        if (nums[0] == 0 && nums[nums.size()-1] == 0) return {{0,0,0}};
        for (auto i = 0; i < nums.size()-2; ++i) {
            if (nums[i] > 0) {
                for (auto i:ans) {
                    v.push_back(i);
                }  
                return v; 
            }
            int j = i+1, k = nums.size()-1;
            while (j < k) {
                if (nums[j] + nums[k] + nums[i] == 0) {
                    ans.insert({nums[i], nums[j], nums[k]});
                    j++;
                }
                else if (nums[j] + nums[k] + nums[i] > 0) {
                    k--;
                }
                else if (nums[j] + nums[k] + nums[i] < 0) {
                    j++;
                }
            }
        }   
        
        for (auto i:ans) {
            v.push_back(i);
        }
        return v; 
    }
};