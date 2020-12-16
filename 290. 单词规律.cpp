class Solution {
public:

    vector<string> split(string& s) {
        string tem;
        vector<string> ans;
        for (auto& i : s) {
            if (i == ' ') ans.push_back(tem), tem = "";
            else tem += i;
        }
        ans.push_back(tem);
        return ans;
    }

    bool wordPattern(string pattern, string s) {
        vector<string> v = split(s);
        if (v.size() != pattern.size()) return false;
        int size = pattern.size();
        map<char, string> m;
        map<string, char> stoc;
        for (int i = 0; i < size; ++i) {
            if (m[pattern[i]] == "" && stoc.count(v[i]) == 0) {
                m[pattern[i]] = v[i], stoc[v[i]] = pattern[i];
            }
            else if (m[pattern[i]] == "" && stoc.count(v[i]) != 0) return false;
            else if (m[pattern[i]] != "" && stoc.count(v[i]) == 0) return false;
            else {
                if (!(m[pattern[i]] == v[i] && stoc[v[i]] == pattern[i])) return false;
            }
        }
        return true;
    }
};