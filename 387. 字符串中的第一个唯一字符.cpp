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

class Solution {
public:
    int firstUniqChar(string s) {
        if (s.empty()) return -1;
        int arr[26]{0};
        for (auto& i:s) {
            arr[i-'a']++;
        }
        for (auto i = 0; i < s.size(); ++i) {
            if (arr[s[i]-'a'] == 1) return i;
        }
        return -1;
    }
};