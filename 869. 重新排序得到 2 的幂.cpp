class Solution {
public:

    vector<int> count(long long num) {
        vector<int> v(10, 0);
        while (num != 0) {
            v[num % 10]++;
            num /= 10;
        }
        return v;
    }

    bool reorderedPowerOf2(int N) {
        long long Num = N;
        long long num = 1;
        for (auto i = 0; i < 32; ++i) {
            if (num > 9 * Num) return false;
            if (count(Num) == count(num)) return true;
            num <<= 1;
        }
        return false;
    }
};