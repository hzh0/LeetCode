class Solution {
public:

    bool less(string s1, string s2) {
        for (auto i = 0; i < s1.size(); ++i) {
            if (s1[i] > s2[i]) return false;
        }
        return true;
    }

    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return less(s1,s2) || less(s2,s1);
    }
};