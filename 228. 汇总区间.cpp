class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) return {};
        vector<string> ans;
        int start = nums[0], end = start;
        for (auto i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i-1] + 1) {
                end++;
            }
            else {
                if (start == end) {
                    ans.push_back(to_string(start));   
                }
                else {
                    ans.push_back(to_string(start) + "->" + to_string(end));
                }
                start = nums[i];
                end = start;
            }
        }
        if (start == end) {
            ans.push_back(to_string(start));   
        }
        else {
            ans.push_back(to_string(start) + "->" + to_string(end));
        }
        return ans;
    }
};