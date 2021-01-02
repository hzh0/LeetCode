class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) {
            return nums;
        }
        deque<int> dq;
        vector<int> ans;
        int left = 0, right = left + k - 1;
        for (auto i = left; i <= right; ++i) {
            if (dq.empty()) {
                dq.push_back(i);
            }
            else {
                while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                    dq.pop_back();
                }
                dq.push_back(i);
            }
        }
        ans.push_back(nums[dq.front()]);
        left++;
        right++;
        while (right < nums.size()) {
            while (!dq.empty() && nums[right] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(right);
            if (!dq.empty() && dq.front() < left) {
                dq.pop_front();
            }
            ans.push_back(nums[dq.front()]);
            left++;
            right++;
        }
        return ans;
    }
};