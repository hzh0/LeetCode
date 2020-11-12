class Solution {
public:

    static bool cmp(vector<int> v1, vector<int> v2) {
        if (v1[0] > v2[0]) return true;
        if (v1[0] == v2[0]) return v1[1] < v2[1];
        return false;
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        if (people.empty()) return {};
        if (people.size() == 1) return people;
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> ans;
        for (auto i : people) ans.insert(ans.begin() + i[1], i);
        return ans;
    }
};