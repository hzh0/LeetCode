class Solution {
public:

    class Djset {
    public:
        vector<int> parents;
        int count;
        Djset(int n) {
            for (auto i = 0; i < n; ++i) {
                parents.push_back(i);
            }
            count = n;
        }

        int find(int num) {
            if (parents[num] != num) {
                parents[num] = find(parents[num]);
            }
            return parents[num];
        }

        void Union(int num1, int num2) {
            int x = find(num1), y = find(num2);
            if (x != y) {
                parents[x] = y;
                count--;
            }
        }
    };


    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> v;
        int ans = 0;
        for (auto i = 0; i < points.size() - 1; ++i) {
            for (auto j = i + 1; j < points.size(); ++j) {
                v.push_back({ i,j,abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]) });
            }
        }

        sort(v.begin(), v.end(), [](vector<int>& v1, vector<int>& v2) {
            return v1[2] < v2[2];
            });
        
        Djset ds(points.size());

        int count = 0;
        for (auto i : v) {
            if (ds.find(i[0]) != ds.find(i[1])) {
                ds.Union(i[0], i[1]);
                ans += i[2];
            }
            if (ds.count == 1) {
                return ans;
            }
        }
        return ans;
    }
};