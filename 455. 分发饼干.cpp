class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int gs = g.size(), ss = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0;
        int ans = 0;
        while(i < gs && j < ss) {
            if (g[i] <= s[j]) {
                i++;
                j++;
                ans++;
            }
            else if (g[i] > s[j]) {
                j++;
            }
        }
        return ans;
    }
};