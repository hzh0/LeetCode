class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return false;
        int size = s.size();
        int first = 1, second = 1, third = 1;
        int num;
        for (auto i = 1; i < size; ++i) {
            if (s[i] == '0') {
                if (s[i - 1] == '1' || s[i - 1] == '2') {
                    third = first;
                    first = 0;
                }
                else return 0;
            }
            else {
                num = (s[i - 1] - '0') * 10 + s[i] - '0';
                if (num <= 26) third = first + second;
                else third = second;
                first = second;
            }
            second = third;
        }
        return third;

    }
};