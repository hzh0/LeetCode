class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int num = 0;
        vector<bool> ans(A.size(), false);
        for (auto i = 0; i < A.size(); ++i) {
            num = num*2%5 + A[i];
            if (num % 5 == 0) {
                ans[i] = true;
            }
        }
        return ans;
    }
};