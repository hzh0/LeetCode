class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == 2) return x*x;
        long long num = abs(n);
        double ans = 1.0;
        double curx = x;
        while(num > 0) {
            if (num % 2) {
                ans *= curx;
            }
            curx *= curx;
            num /= 2;
        }
        return n < 0 ? 1.0/ans:ans;
    }
};