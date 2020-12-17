class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        map<int, int> m;
        for (auto& i : nums1) m[i]++;
        for (auto& i : nums2) {
            if (m[i]) {
                ans.push_back(i);
                m[i]--;
            }
        }
        return ans;
    }
};