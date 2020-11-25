class Solution {
public:
    string sortString(string s) {
        int c[26]{0};
        for (auto i : s) c[i-'a']++;
        string ans;
        while(ans.size() != s.size()) {
            for (auto i = 0; i < 26; ++i) {
                if (c[i] > 0) {
                    ans += (char)(i+'a');
                    c[i]--;
                }
            }
            for (auto i = 25; i >= 0; --i) {
                if (c[i] > 0) {
                    ans += (char)(i+'a');
                    c[i]--;    
                }
            }
        }  
        return ans;  
    }
};