// 遍历数组，找到山顶 i, 即满足 A[i] > A[i - 1] && A[i] > A[i + 1] 的点
// 然后向左右两个方向下山，满足条件就将山脉长度加一
// 当左右两边都不能继续满足条件了则继续去寻找下一个山峰
class Solution {
public:
    int longestMountain(vector<int>& A) {
        if (A.size() < 3) return 0;
        int ans = 0;
        int left, right;
        for (auto i = 1; i < A.size() - 1; ++i) {
            if (A[i] > A[i - 1] && A[i] > A[i + 1]) {
                int res = 3;
                left = i-1, right = i+1;
                while (left > 0 || right < A.size()-1) {
                    if (left - 1 >= 0) {
                        if (A[left] > A[left - 1]) {
                            res++;
                            left--;
                        }
                        else {
                            left = -1;
                        }
                    }
                    if (right + 1 < A.size()) {
                        if (A[right] > A[right + 1]) {
                            res++;
                            right++;
                        } 
                        else {
                            right = A.size();
                        }
                    }
                }
                ans = max(ans, res);
            }
        }
        return ans;
    }
};