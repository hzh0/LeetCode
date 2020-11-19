class Solution {
public:

    vector<string> ans;

    void dfs(vector<vector<char>>& space, int depth, string& s) {
        if (depth == space.size()) {
            ans.push_back(s);
            return;
        }
        for (auto j : space[depth]) {
            s.push_back(j);
            dfs(space, depth + 1, s);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<vector<char>> v = { {},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},
            {'j','k','l' },{'m','n','o' },{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'} };
        vector<vector<char>> space;
        for (auto i : digits) space.push_back(v[(int)(i-'0')]);
        string s;
        dfs(space, 0, s);
        return ans;
    }
};