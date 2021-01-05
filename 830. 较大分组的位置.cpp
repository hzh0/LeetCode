class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        if (s.size() < 3) {
            return {};
        }
        vector<vector<int>> ans;
        int start = 0, end = 0;
        s += '1';
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) {
                end++;
            }
            else {
                if (end - start >= 2) {
                    ans.push_back({start, end});
                }
                start = i;
                end = i;
            }
        }
        
        return ans;
    }
};