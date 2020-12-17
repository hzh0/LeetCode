class Solution {
public:
    int firstUniqChar(string s) {
        if (s.empty()) return -1;
        map<char, int> m;
        for (auto& i : s) m[i]++;
        for (auto i = 0; i < s.size(); ++i) if (m[s[i]] == 1) return i;
        return -1;
    }
};