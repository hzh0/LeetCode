class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int ans = 0;
        for (auto i = 0; i < citations.size(); ++i) {
            ans = max(min((int)citations.size()-i, citations[i]), ans);
        }
        return ans;
    }
};