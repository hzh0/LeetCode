/*
给你一个整数数组 arr 。请你将数组中的元素按照其二进制表示中数字 1 的数目升序排序。

如果存在多个数字二进制中 1 的数目相同，则必须将它们按照数值大小升序排列。

请你返回排序后的数组。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-integers-by-the-number-of-1-bits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
对于整数 n , n & (n-1) 可以消去 n 二进制形式的最低位的 1
所以可以用 n & (n-1) 进行 1 的个数的统计，之后再排序即可
*/

class Solution {
public:

    static int bitcount(int n) {
        int count = 0;
        while ( n = n & (n-1)) count ++;
        return count;
    }

    static bool com(int a, int b) {
        if (bitcount(a) == bitcount(b)) {
            return a < b;
        }
        return bitcount(a) < bitcount(b);
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), com);
        return arr;
    }
};