class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.empty()) return true;
        int size = popped.size();
        int popindex = 0, pushindex = 0;
        stack<int> s;
        while (true) {
            if (s.empty() || s.top() != popped[popindex]) {
                if (pushindex == size && s.top() != popped[popindex]) return false;
                s.push(pushed[pushindex]);
                pushindex++;              
            }
            else if (s.top() == popped[popindex]) {
                s.pop();
                popindex++;
                if (popindex == size) return true;
            }
        }
        return false;
    }
};