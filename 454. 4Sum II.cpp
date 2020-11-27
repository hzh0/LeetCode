class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int size = A.size();
        int res = 0;
        map<int, int> m;
        for (auto& i:A) {
            for (auto& j:B) m[i+j]++;
        }
        for (auto& i:C) {
            for (auto& j:D) res += m[-(i+j)]; 
        }
        return res;
    }
};