class Solution {
public:
    string removeKdigits(string num, int k) {
        num += '0';
        for (auto i = 0; i < k; ++i) {
            for (auto it = num.begin(); it != num.end()-1; ++it) {
                if (*it > *(it+1)) {
                    num.erase(it);
                    break;
                }
            }
        }
        num = num.substr(0,num.size()-1);
        for (auto it = num.begin(); it != num.end();) {
            if (*it == '0') num.erase(it);
            else break;
        }
        return num == "" ? "0" : num;
    }
};