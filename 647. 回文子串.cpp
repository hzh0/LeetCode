class Solution {
public:

    bool judge(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int countSubstrings(string s) {
        int ans = 0;
        for (auto i = 0; i < s.size(); ++i) {
            for (auto j = 0; j <= i; ++j) {
                if (judge(s, j, i)) ans += 1;
            }
        }
        return ans;
    }
};