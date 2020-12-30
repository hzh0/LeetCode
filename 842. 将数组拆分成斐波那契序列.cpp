class Solution {
public:
    
    vector<long long> ans;

    bool dfs(string& s, int index) {
        if (index == s.size() && ans.size() >= 3) {
            for (auto&i:ans) {
                if (i > INT_MAX){
                    return false;
                }
            }
            return true;
        }
        for (int i = index; i < s.size(); ++i) {
            if (i > index && s[index] == '0') {
                break;
            }
            long long num = atoll(s.substr(index, i-index+1).c_str());
            if (num > INT_MAX) {
                break;
            }
            if (ans.size() >= 2 && num > ans[ans.size() - 1] + ans[ans.size() - 2]) {
                break;
            }
            if (ans.size() <= 1 || num == ans[ans.size() - 1] + ans[ans.size() - 2]) {
                ans.push_back(num);
                if (dfs(s, i + 1)) {
                    return true;
                }
                ans.pop_back();
            }
        }
        return false;
    }

    vector<int> splitIntoFibonacci(string S) {
        dfs(S, 0);
        vector<int> res;
        for (auto&i:ans) {
            res.push_back((int)i);
        }
        return res;
    }
};