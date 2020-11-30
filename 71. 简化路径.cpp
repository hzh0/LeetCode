class Solution {
public:

    inline vector<string> split(string& path) {
        string tem = "";
        vector<string> ans;
        for (auto i : path) {
            if (i == '/' && tem != "") ans.push_back(tem), tem = "";
            else if(i!='/') tem += i;
        }
        if (tem != "") ans.push_back(tem);
        return ans;
    }

    string simplifyPath(string path) {
        if (path == "") return "";
        vector<string> f = split(path);
        stack<string> s;
        string ans;
        for (auto& i : f) {
            if (i == ".") continue;
            if (i == "..") { if (!s.empty()) s.pop(); }
            else s.push(i);
        }
        while (!s.empty()) {
            ans = "/" + s.top()+ ans;
            s.pop();
        }
        return ans == "" ? "/" : ans;
    }
};