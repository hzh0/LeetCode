class Solution {
public:
    int numTrees(int n) {
        vector<int> v(n+1,1);
        for (auto i = 2; i <=n; ++i) {
            v[i] = 0;
            for (auto j = 0; j < i; ++j) {
                v[i] += v[j]*v[i-1-j]; 
            }
        }
        return v[n];
    }
};