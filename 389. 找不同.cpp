class Solution {
public:
    char findTheDifference(string s, string t) {
        string S = s+t;
        int a=0;
        for (auto i = 0; i < S.size(); ++i) {
            a ^= S[i];
        }
        return (char)a;
    }
};