class Solution {
public:
    vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
        int sum1 = accumulate(array1.begin(), array1.end(), 0);
        int sum2 = accumulate(array2.begin(), array2.end(), 0);
        if (abs(sum1 - sum2) % 2) return {};
        int target = abs(sum1 - sum2) / 2;
        map<int, int> m1, m2;
        for (auto& i : array1) m1[i]++;
        for (auto& i : array2) m2[i]++;
        if (sum1 < sum2) {
            for (auto& i : array1) {
                if (m2[i + target]) return { i, i + target };
            }
        }
        else {
            for (auto& i : array1) {
                if (m2[i - target]) return { i, i - target };
            }
        }
        return {};       
    }
};