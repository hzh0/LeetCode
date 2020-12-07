class Solution {
public:
    string reverseWords(string s) {
        string ans, tem;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == ' ' && !tem.empty()) {
                ans = ans + tem + " ";
                tem.clear();
            }
            else if (s[i] != ' ') tem = s[i] + tem;
        }
        if (!tem.empty()) ans = ans + tem;
        if (ans[ans.size() - 1] == ' ') ans.pop_back();
        return ans;

    }
};