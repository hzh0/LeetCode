class Solution {
public:
    int fib(int N) {
        if (N <= 1) {
            return N;
        }
        int f0 = 0, f1 = 1, tem;
        for (auto i = 2; i <= N; ++i) {
            tem = f1;
            f1 = f0 + f1;
            f0 = tem;
        }
        return f1;
    }
};