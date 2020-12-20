class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if (target.size() != arr.size()) return false;
        vector<int> v(1001,0);
        for (auto& i:target) v[i]++;
        for (auto& i:arr) {
            v[i]--;
            if (v[i] < 0) return false;
        }
        return true;
    }
};