class Solution {
public:
    int climbStairs(int n) {
        if (n==1)return 1;
        if (n==2) return 2;
        long f1 = 1, f2 = 2;
        for (auto i = 3; i<=n; ++i) {
            int tem = f2;
            f2 = f1+f2;
            f1=tem;
        }
        return f2;
    }
};