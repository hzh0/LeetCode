class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(),[](vector<int>& v1, vector<int>& v2){
            return v1[1] < v2[1];
        });
        int cur = INT_MIN;
        int ans = 0;
        for (auto& i : pairs) {
            if (cur < i[0]) {
                cur = i[1];
                ans++;
            }
        }
        return ans;
    }
};