class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> ans = A;
        int oindex =0, aindex = 1;
        for (auto i : A) {
            if (i % 2) {
                ans[aindex] = i;
                aindex+=2;
            }
            else {
                ans[oindex] = i;
                oindex+=2;
            }
        }
        return ans;
    }
};