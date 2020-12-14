class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int arr[1001]{ 0 };
        for (auto& i : trips) {
            for (auto j = i[1]; j < i[2]; ++j) {
                arr[j] += i[0];
                if (arr[j] > capacity) return false;
            }
        }
        return true;
    }
};