class Solution {
public:
    string removeDuplicateLetters(string s) {
        int lastindex[26];
        for (int i = 0; i < s.size(); ++i) {
            lastindex[s[i] - 'a'] = i;
        }
        bool visited[26]{ false };
        stack<char> sk;
        for (int i = 0; i < s.size(); ++i) {
            if (visited[s[i] - 'a']) continue;
            if (sk.empty() || s[i] > sk.top()) {
                sk.push(s[i]);
            } 
            else {         
                while (!sk.empty() && sk.top() > s[i] && lastindex[sk.top() - 'a'] > i) {
                    visited[sk.top() - 'a'] = false;
                    sk.pop();
                }
                sk.push(s[i]);              
            } 
            visited[s[i] - 'a'] = true;       
        }
        string ans;
        while (!sk.empty()) {
            ans = sk.top() + ans;
            sk.pop();
        }
        return ans;
    }
};