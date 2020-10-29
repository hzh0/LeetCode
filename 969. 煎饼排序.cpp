/*
给定数组 A，我们可以对其进行煎饼翻转：我们选择一些正整数 k <= A.length，然后反转 A 的前 k 个元素的顺序。我们要执行零次或多次煎饼翻转（按顺序一次接一次地进行）以完成对数组 A 的排序。

返回能使 A 排序的煎饼翻转操作所对应的 k 值序列。任何将数组排序且翻转次数在 10 * A.length 范围内的有效答案都将被判断为正确。

提示：
    1. 1 <= A.length <= 100
    2. A[i] 是 [1, 2, ..., A.length] 的排列
*/

/*
这道题，可以从后往前依次翻转，使每个数字回到其该在的位置，也就完成了目的
例如:我们先将[3,2,4,1]变为[?,?,?,4]的形式
可以先找到数字4的位置,将数字4前进行翻转变成[4,2,3,1],接下来我们再整体翻转[1,3,2,4],这样我们把数字4移动列表底.
然后,我们再将[1,3,2,4]变为[?,?,3,4]的形式,还是用刚才的方法,首先找到数字3,翻转数字3前面的所有数字将3移动到最前端,然后再翻转前3个数字，这样3就到了自己的位置
再接着对数字2进行上述操作，使其到自己的位置
依次类推
*/

class Solution {
public:
    
    vector<int> ans;

    void reverse(vector<int>& arr, int n) {
        for (auto i = 0; i < n / 2; ++i) swap(arr[i], arr[n-i-1]);
        ans.push_back(n);
    }
    
    void getans(vector<int>& arr, int n) {
        if (n == 0) return;
        int index = 0;
        for (auto i = 0; i < n; ++i)
            if (arr[i] == n) index = i;
        if (index == n - 1) getans(arr, n - 1);
        else {
            reverse(arr, index + 1);
            reverse(arr, n);
            getans(arr, n - 1);
        }
    }

    vector<int> pancakeSort(vector<int>& arr) {
        getans(arr, arr.size());
        return ans;
    }
};