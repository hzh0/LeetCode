class Solution {
public:
    int divide1(long dividend, long divisor) {
        if (dividend < divisor) return 0;
        long tem = divisor;
        long res = 1;
        while (dividend >= divisor) {
            divisor <<= 1;
            res <<= 1;
        }
        divisor >>= 1;
        res >>= 1;
        return res + divide(dividend - divisor, tem);
    }

    int divide(int num11, int num21) {
        long num1 = num11, num2 = num21;
        bool flag = false;
        if (num1 == 0) return 0;
        if (num2 == 0) return INT_MAX;
        if (num2 == 1) return num1;
        if (num1 == INT_MIN && num2 == -1) return INT_MAX;
        if (num1 > 0 && num2 < 0 || num1 < 0 && num2 > 0) flag = true;
        int num = divide1(abs(num1), abs(num2));
        return flag ? -num:num;
    }
};