class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> ans;
        int a[8][2] = { {-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1} };
        set<vector<int>> s;
        for (auto& i : queens) s.insert(i);
        int row = king[0], col = king[1];
        for (auto i = 0; i < 8; ++i) {
            for (int j = row, k = col; j < 8 && k < 8 && j >= 0 && k >= 0; j += a[i][0], k += a[i][1]) {
                if (s.count({ j,k })) {
                    ans.push_back({ j,k });
                    break;
                }
            }
        }
        return ans;
    }
};