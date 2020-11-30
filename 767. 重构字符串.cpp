class Solution {
public:
    string reorganizeString(string S) {
        if (S=="")return"";
        map<char, int> m;
        vector<pair<char, int>> v;
        int size = S.size();
        string ans(S);
        for (auto& i : S) m[i]++;
        for (auto& i : m) v.push_back(i);
        sort(v.begin(),v.end(), [](pair<char, int>& p1, pair<char, int>& p2) {return p1.second > p2.second; });
        if (v[0].second > (size + 1) / 2) return "";
        int index = 0;
        for (auto i = 0; i < v.size(); ++i) {
            while (v[i].second > 0) {
                ans[index] = v[i].first;
                v[i].second--;
                index += 2;
                if (index >= size) index = 1;
            }
        }
        return ans;      
    }
};