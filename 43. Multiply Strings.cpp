class Solution {
public:

    string sads(string& s1, string& s2) {
        int index1 = s1.size() - 1, index2 = s2.size() - 1;
        int cur = 0, tem;
        while (index1 >= 0 || index2 >= 0) {
            if (index1 >= 0 && index2 >= 0) {
                tem = s2[index2] - '0';
                s2[index2] = (s1[index1] - '0' + tem + cur) % 10 + '0';
                cur = (s1[index1] - '0' + tem +cur) / 10;
                
            }
            else if (index2 >= 0 && index1 < 0) {
                tem = s2[index2] - '0';
                s2[index2] = (tem + cur) % 10 + '0';
                cur = (tem +cur) / 10;
            }
            index1--;
            index2--;
        }
        if (cur != 0) s2 = (char)(cur + '0') + s2;
        return s2;
    }

    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        string ans, tem;
        int cur = 0, num;
        for (int i = num2.size() - 1; i >= 0; --i) {
            cur = 0;
            for (int j = num1.size() - 1; j >= 0; --j) {
                num = (num1[j] - '0') * (num2[i] - '0') + cur;
                cur = num / 10;
                num %= 10;
                tem = (char)(num + '0') + tem;
            }
            if (cur > 0) tem = (char)(cur + '0') + tem;
            for (auto k = 0; k < num2.size() - 1 - i; ++k) tem += '0';
            ans = sads(ans, tem);
            tem = "";
        }
        return ans;
    }
};