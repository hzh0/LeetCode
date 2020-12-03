class Solution {
public:

    bool func(int n) {
        for (auto i = 2; i*i <= n; ++i) {
            if (n % i == 0) return false;
        }
        return true;
    }

    int countPrimes(int n) {
        if (n <= 2) return 0;
        if (n == 3) return 1;
        vector<bool> a(n+1, true);
        a[0] = false;
        a[1] = false;
        int index = 4;
        while (index <= n) {
            a[index] = false;
            index += 2;
        }
        int ans = 1;
        for (auto i = 3; i < n; i += 2) {
            if (a[i] && func(i)) {
                ans++;
                index = 2 * i;
                while (index <= n) {
                    a[index] = false;
                    index += i;
                }
            }
        }
        return ans;
    }
};