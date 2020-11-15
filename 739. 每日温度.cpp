class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ans(T.size(),0);
        stack<int> s;
        for (auto i = 0; i < T.size(); ++i) {
            if (s.empty()) s.push(i);
            else{
                while(!s.empty() && T[i] > T[s.top()]) {
                    ans[s.top()] = i-s.top();
                    s.pop();  
                }
                s.push(i);
            }
        }
        return ans;   
    }
};