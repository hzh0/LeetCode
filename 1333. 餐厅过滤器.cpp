class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<pair<int, int>> vp;
        vector<int> ans;
        for (auto& i : restaurants) {
            if (veganFriendly == 1) {
                if (i[2] == 0) {
                    continue;
                }
            }
            if (i[3] <= maxPrice && i[4] <= maxDistance) {
                vp.push_back({ i[0],i[1] });
            }
        }
        sort(vp.begin(), vp.end(), [](pair<int, int>& p1, pair<int, int>& p2) {
            if (p1.second != p2.second) {
                return p1.second > p2.second;
            }
            return p1.first > p2.first;
            });
        for (auto& i : vp) {
            ans.push_back(i.first);
        }
        return ans;
    }
};