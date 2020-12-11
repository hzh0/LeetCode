class Solution {
public:
    string modifyString(string s) {
        if (s.empty()) return "";
        if (s.size() == 1) return s == "?" ? "a" : s;
        if (s[0] == '?') {
            if (s[1] == 'z') s[0] = 'y';
            else if (s[1] == '?') s[0] = 'a';
            else s[0] = s[1] + 1;
        }
        for (auto i = 1; i < s.size()-1; ++i) {
            if (s[i] == '?') {
                if (s[i - 1] == 'a' && s[i + 1] == 'z') s[i] = 'b';
                else if (s[i + 1] == 'a' && s[i - 1] == 'z') s[i] = 'b';
                else if (s[i + 1] == '?') {
                    if (s[i - 1] == 'z') s[i] = 'y';
                    else s[i] = s[i - 1] + 1;
                }
                else {
                    if (s[i - 1] == 'a' || s[i + 1] == 'a') s[i] = max((int)s[i - 1], (int)s[i + 1]) + 1;
                    else s[i] = min((int)s[i - 1], (int)s[i + 1]) - 1;
                }
            }
        }
        if (s[s.size() - 1] == '?') {
            if (s[s.size() - 2] == 'z') s[s.size() - 1] = 'y';
            else s[s.size() - 1] = s[s.size() - 2] + 1;
        }
        return s;
    }
};