class Solution {
public:

    int isflag(string& s, int i, int j) {
        while(i >= 0 && j < s.size() && s[i] == s[j])
        {
            i--;
            j++;
        }
        return j-i-1;
    }

    string longestPalindrome(string s) {
        int ans = 0;
        string res;
        for (auto i = 0; i < s.size(); ++i) {
            int num1 = isflag(s,i,i+1);
            int num2 = isflag(s,i,i);
            int num = max(num1, num2);
            if (num > ans) {
                int start = i - (num - 1) / 2;
                res = s.substr(start, num);
                ans = num;
            }
        }
        return res;
    }
};