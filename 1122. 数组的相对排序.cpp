class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> m;
        vector<int> ans;
        for (auto i : arr1) m[i]++;
        for (auto i : arr2) {
            if (m[i] > 0) {
                ans.insert(ans.end(), m[i], i);
                m[i] = 0;
            }
        }
        for (auto i : m) {
            if (i.second != 0) ans.insert(ans.end(), i.second, i.first);
        }
        return ans;
    }
};