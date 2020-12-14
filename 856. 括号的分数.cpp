class Solution {
public:
    int scoreOfParentheses(string S) {
        if (S.empty()) return 0;
        // -1 == '('  ,  0 == ')'
        stack<int> s;
        for (auto& i : S) {
            if (i == '(') s.push(-1);
            else {
                int num;
                if (s.top() == -1) {
                    s.pop();
                    num = 1;
                    while (!s.empty() && s.top() != -1) {
                        num += s.top();
                        s.pop();
                    }
                }
                else {
                    num = s.top();
                    s.pop();
                    num *= 2;
                    s.pop(); 
                    while (!s.empty() && s.top() != -1) {
                        num += s.top();
                        s.pop();
                    }                                   
                }
                s.push(num);
            }
        }
        return s.top();
    }
};