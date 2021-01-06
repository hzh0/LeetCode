class Solution {
public:
    set<string> visted;
    map<pair<string, string>, double> m;

    double dfs(string start, string end) {
        if (visted.count(start)) {
            return 0;
        }
        if (m.count({ start,end })) {
            return m[{start, end}];
        }
        visted.insert(start);
        double res = 0;
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->first.first == start) {
                double num = dfs(it->first.second, end);
                res = it->second * num ;
                if (res != 0) {
                    m[{start, end}] = res;
                    m[{end, start}] = 1 / res;
                    break;
                }
            }
        }
        for (auto it = visted.begin(); it != visted.end(); ++it) {
            if ((*it) == start) {
                visted.erase(it);
                break;
            }

        }
        return res;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, int> mcount;
        vector<double> ans;
        for (auto i = 0; i < equations.size(); ++i) {
            mcount[equations[i][0]]++;
            mcount[equations[i][1]]++;
            m[{equations[i][0], equations[i][1]}] = values[i];
            m[{equations[i][1], equations[i][0]}] = 1 / values[i];
        }
        for (auto i : queries) {

            if (mcount.count(i[0]) == 0 || mcount.count(i[1]) == 0) {
                ans.push_back(-1.0);
            }
            else {
                if (m.count({ i[0],i[1] })) {
                    ans.push_back(m[{i[0], i[1]}]);
                }
                else {
                    dfs(i[0], i[1]) == 0 ? ans.push_back(-1.0) : ans.push_back(dfs(i[0], i[1]));
                }
            }
        }
        return ans;

    }
};