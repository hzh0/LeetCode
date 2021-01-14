#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int ans = 0;
        for (auto i = 0; i < citations.size(); ++i) {
            ans = max(min(citations.size()-i, citations[i]), ans);
        }
        return ans;
    }
};