class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        int cur = INT_MAX;
        sort(arr.begin(), arr.end());
        for (auto i = 0; i < arr.size() - 1; ++i) {
            if (arr[i + 1] - arr[i] < cur) {
                ans.clear();
                cur = arr[i + 1] - arr[i];
                ans.push_back({ arr[i],arr[i + 1] });
            }
            else if (arr[i + 1] - arr[i] == cur) ans.push_back({ arr[i],arr[i + 1] });
        }
        return ans;
    }
};