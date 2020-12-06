class Solution {
public:

    bool wordBreak(string s, vector<string>& wordDict) {
        if (wordDict.empty()) return false;
        sort(wordDict.begin(), wordDict.end(), [](string& s1, string& s2) {return s1.size() > s2.size(); });
        unordered_map<string, int> um;
        for (auto i : wordDict) um[i]++;
        int maxlen = wordDict[0].size();
        vector<bool> v(s.size() + 1, false);
        v[0] = true;
        for (auto i = 0; i < s.size(); ++i) {
            for (auto j = i; j >= 0; --j) {
                v[i + 1] = v[i+1] || um[s.substr(j, i - j + 1)] && v[j];
            }
        }
        return v[s.size()];
    }
};