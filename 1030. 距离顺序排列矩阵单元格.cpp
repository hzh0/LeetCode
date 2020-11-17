class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> v;
        for (auto i = 0; i < R; ++i) {
            for (auto j = 0; j < C; ++j) {
                v.push_back({i,j});
            }
        }
        sort(v.begin(), v.end(), 
            [r0,c0](vector<int> v1, vector<int> v2)
            {
                int n1 = abs(v1[0]-r0) + abs(v1[1]-c0);
                int n2 = abs(v2[0]-r0) + abs(v2[1]-c0);
                return n1 < n2;
            }
        );
        return v;
    }
};