class Solution {
public:

    string stn(string& s) {
        int count=1;
        char c = s[0];
        string res;
        for (auto i = 1; i < s.size(); ++i) {
            if (s[i] == c) count++;
            else {
                res += (to_string(count) + c);
                count = 1;
                c = s[i];
            }
        }
        res += (to_string(count) + c);
        return res;
    }

    string countAndSay(int n) {
        if (n==1) return "1";
        string s = "1";
        for (int i = 1; i < n; ++i) {
            s = stn(s);
        }
        return s;
    }
};