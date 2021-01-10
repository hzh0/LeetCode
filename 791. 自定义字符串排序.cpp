class Solution {
public:
    string customSortString(string S, string T) {
        int a[26]{0};
        string ans;
        for (auto& i : T) {
            a[i-'a']++;
        }
        for (auto& i : S) {
            while(a[i-'a'] != 0) {
                ans += i;
                a[i-'a']--;
            }
        }
        for (auto i = 0; i < 26; ++i) {
            while(a[i] !=0) {
                ans += (char)(i+'a');
                i--;
            }
        }
        return ans;
    }
};