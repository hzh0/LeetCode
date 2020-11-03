/*
给定一个整数数组 A，如果它是有效的山脉数组就返回 true，否则返回 false。

让我们回顾一下，如果 A 满足下述条件，那么它是一个山脉数组：

A.length >= 3
在 0 < i < A.length - 1 条件下，存在 i 使得：
A[0] < A[1] < ... A[i-1] < A[i]
A[i] > A[i+1] > ... > A[A.length - 1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-mountain-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
设置一个 bool 变量来判断当前是上山还是下山
遇到A[i+1] < A[i] 后开始下山，一旦下山后不能再上山
需要遍历完数组最后判断一下是否一直是在上山，如果一直上山而没下山，也返回 false
*/

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if (A.size() <= 1) return false;
        if (A[0] > A[1]) return false;
        bool up = true;
        for (auto i = 1; i < A.size(); ++i) {
            if (A[i] == A[i-1]) return false;
            if (up && A[i] > A[i-1]) continue;
            else if (!up && A[i] > A[i-1]) return false;
            else if (up && A[i] < A[i-1]) up = false;
        }
        if (up) return false;
        return true;
    }
};