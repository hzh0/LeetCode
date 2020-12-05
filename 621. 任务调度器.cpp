class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) return tasks.size();
        if (tasks.empty()) return 0;
        map<char, int> m;
        for (auto i : tasks) m[i]++;
        vector<pair<char, int>> v;
        for (auto i : m) v.push_back(i);
        sort(v.begin(), v.end(), [](pair<char, int>& p1, pair<char, int>& p2) {return p1.second > p2.second; });
        int k = v[0].second;
        int ms = 0;
        for (auto i = 1; i < v.size(); ++i) {
            if (v[i].second == v[i - 1].second) ms++;
            else break;
        }
        return (n+1)*k-n+ms > tasks.size() ? (n+1)*k-n+ms : tasks.size();
    }
};