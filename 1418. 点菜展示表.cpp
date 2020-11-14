class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<int, map<string, int>> m;
        for (auto i : orders) m[atoi(i[1].c_str())][i[2]]++;
        set<string> name;
        for (auto i : m) {
            for (auto j : i.second) {
                name.insert(j.first);
            }
        }
        vector<vector<string>> ans;
        vector<string> tem;
        tem.push_back("Table");
        for (auto i : name) tem.push_back(i);
        ans.push_back(tem);
        for (auto i : m) {
            tem.clear();
            tem.push_back(to_string(i.first));
            for (auto j : name) {
                tem.push_back(to_string(i.second[j]));
            }
            ans.push_back(tem);
        }
        return ans;
    }
};