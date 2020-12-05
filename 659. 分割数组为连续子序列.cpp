class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> m, s;
        for (auto i : nums) m[i]++;
        for (auto i : nums) {
            if (!m[i]) continue;
            if (s[i - 1]) {
                m[i]--;
                s[i - 1]--;
                s[i]++;
            }
            else if (m[i + 1] && m[i + 2]) {
                m[i]--;
                m[i + 1]--;
                m[i + 2]--;
                s[i + 2]++;
            }
            else return false;
        }
        return true;
    }
};