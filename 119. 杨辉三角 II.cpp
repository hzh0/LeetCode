class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return {1};
        if (rowIndex == 1) return { 1,1 };
        vector<int> top = { 1,1 };
        vector<int> down;
        for (auto i = 2; i <= rowIndex; ++i) {
            down.clear();
            down.push_back(1);
            for (auto j = 1; j < i; ++j) down.push_back(top[j - 1] + top[j]);
            down.push_back(1);
            top = down;
        }
        return down;
    }
};