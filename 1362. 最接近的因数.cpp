class Solution {
public:

    vector<int> func(int num) {
        int st = sqrt(num);
        for (auto i = st; i >= 1; --i) {
            if (num % i == 0) return { i, (num / i) };
        }
        return {0,0};
    }

    vector<int> closestDivisors(int num) {
        vector<int> a1 = func(num + 1);
        vector<int> a2 = func(num + 2);
        int n1 = abs(a1[0] - a1[1]);
        int n2 = abs(a2[0] - a2[1]);
        return n1 < n2 ? a1 : a2;
    }
};