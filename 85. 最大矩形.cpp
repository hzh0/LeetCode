class Solution {
public:

    int getMaxArea(vector<int>& v) {
        v.insert(v.begin(), 0);
        v.push_back(0);
        stack<int> stack;
        stack.push(0);
        int height, width;
        int ans = 0;
        for (auto i = 1; i < v.size(); ++i) {
            while (v[i] < v[stack.top()]) {
                height = v[stack.top()];
                stack.pop();
                width = i - stack.top() - 1;
                ans = max(ans, height * width);
            }
            stack.push(i);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int row = matrix.size(), col = matrix[0].size();
        int ans = 0;
        for (auto i = 0; i < row; ++i) {
            vector<int> v;
            for (auto j = 0; j < col; ++j) {
                int num = 0;
                if (matrix[i][j] != '0') {
                    for (auto k = i; k >= 0; --k) {
                        if (matrix[k][j] == '1') {
                            ++num;
                        }
                        else {
                            break;
                        }
                    }
                }
                v.push_back(num);
            }
            ans = max(ans, getMaxArea(v));
        }
        return ans;
    }
};