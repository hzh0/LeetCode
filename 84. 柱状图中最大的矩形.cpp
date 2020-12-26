class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        heights.insert(heights.begin(), 0);
        stack<int> stack;
        stack.push(0);
        int ans = 0;
        int height, width;
        for (auto i = 1; i < heights.size(); ++i) {
            while (heights[i] < heights[stack.top()]) {
                height = heights[stack.top()];
                stack.pop();
                width = i - stack.top() - 1;
                ans = max(ans, height * width);
            }
            stack.push(i);
        }
        return ans;
    }
};