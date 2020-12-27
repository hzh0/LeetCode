class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        int size = s.size();
        if (size == 0) {
            return true;
        }
        map<char, char> m1, m2;
        for (auto i = 0; i < size; ++i) {
            if (m1.count(s[i]) != 0 && m1[s[i]] != t[i] || m2.count(t[i]) != 0 && m2[t[i]] != s[i]) {
                return false;
            }
            m1[s[i]] = t[i];
            m2[t[i]] = s[i];
        }
        return true;
    }
};