class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string num = to_string(N);
        int flag = num.length();
        for (auto i  = num.size()-1; i >=1; --i) {
            if (num[i] < num[i-1]) {
                flag = i;
                num[i-1]--;
            }
        }
        for (auto i = flag; i < num.size(); ++i) num[i] = '9';
        return atoi(num.c_str());
        
    }
};