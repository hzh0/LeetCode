class Solution {
public:
    string decodeString(string s) {
        if (s.empty()) return "";
        stack<string> sk;
        int index = 0;
        string ss;
        int count;
        while (index < s.size()) {
            string tem;
            if (s[index] >= 'a' && s[index] <= 'z') {
                tem += s[index];
                int i = index + 1;
                while (s[i] >= 'a' && s[i] <= 'z') tem += s[i], i++;
                while (!sk.empty() && sk.top() != "[") {
                    tem = sk.top() + tem;
                    sk.pop();
                }
                sk.push(tem);
                index = i;
            }
            else if (s[index] == '[') sk.push("["), index++;
            else if (s[index] >= '0' && s[index] <= '9') {
                tem += s[index];
                int i = index + 1;
                while (s[i] >= '0' && s[i] <= '9') tem += s[i], i++;
                sk.push(tem);
                index = i;
            }
            else {
                ss = sk.top();
                sk.pop();
                sk.pop();
                count = atoi(sk.top().c_str());
                sk.pop();
                string n;
                for (auto i = 0; i < count; ++i) n += ss;
                while (!sk.empty() && sk.top() != "[") {
                    n = sk.top() + n;
                    sk.pop();
                }
                sk.push(n);
                index++;
            }
        }
        string ans;
        while (!sk.empty()) ans = sk.top() + ans, sk.pop();
        return ans;  
    }
};