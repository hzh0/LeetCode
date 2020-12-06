class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) return {};
        vector<vector<int>> vs;
        for (int i = 1; i <= numRows; i++) {
            vector<int> v;
            for (int j = 0; j < i; j++) {
                if (j ==0 || j == i-1) {
                    v.push_back(1);
                }
                else {
                    v.push_back(vs[i-2][j-1] + vs[i-2][j]);
                }
            }
            vs.push_back(v);
        }
        return vs;
    }
};