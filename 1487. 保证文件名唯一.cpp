class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        map<string, int> m;
        vector<string> ans;
        for (auto& i : names) {
            if (m.count(i) == 0) {
                m[i] = 0;
                ans.push_back(i);
            }
            else{
                int index = m[i]+1;
                for (auto j = index;;){
                    string new_name = i + '(' + to_string(j) + ')';
                    if (m.count(new_name)) {
                        ++j;
                    }
                    else{
                        m[new_name] = 0;
                        m[i] = j;
                        ans.push_back(new_name);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};