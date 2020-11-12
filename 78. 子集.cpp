class Solution {
  public:
      vector<vector<int>> subsets(vector<int>& nums) {
          vector<vector<int>> ans;
          ans.push_back({});
          for (auto i : nums) {
              int size = ans.size();
              for (auto j = 0; j < size; ++j) {
                  if (!ans[j].empty()) {
                      vector<int> tem = ans[j];
                      tem.push_back(i);
                      ans.push_back(tem);
                  }
              }
              ans.push_back({ i });
          }
          return ans;
      }
  };