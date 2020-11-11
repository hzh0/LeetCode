/*
给出一个无重叠的 ，按照区间起始端点排序的区间列表。
在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。
*/

/*
给出的区间列表为 intervals , 要插入的区间为 newInterval
用 it 指向 intervals 的首个区间，与 newInterval 比较，
如果 it 指向的区间整个在 newInterval 的右边，也就是 newInterval 的右端点小于 it 的左端点，那么直接将 newInterval 插入到 it 前面返回即可
如果 it 指向的区间整个在 newInterval 的左边，也就是 it 的右端点小于 newInterval 的左端点，那么将 it++ ，开始用 newInterval 与 intervals 的下一区间比较
如果 it 指向的区间与 newInterval 有重叠的部分，那么就将 it 和 newInterval 合并，并在 intervals 中删掉 it ，并将新得到的 newInterval 继续与 it 开始新一轮的比较
若知道 it 遍历到了 intervals 尾部还是没有将 newInterval 插入进去，就说明 newInterval 在整个区间的最右边，那么直接将 newInterval 插入到 intervals 尾部即可
*/

class Solution {
public:

    int over(vector<int>& n, vector<int>& o, int* a) {
        if (n[1] < o[0]) return 1;
        if (n[0] > o[1]) return 2;
        a[0] = min({ n[0], n[1], o[0], o[1] });
        a[1] = max({ n[0], n[1], o[0], o[1] });
        return 3;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty() || newInterval[0] <= intervals[0][0] && newInterval[1] >= intervals[intervals.size() - 1][1] ) 
            return { newInterval };
        auto it = intervals.begin();
        int a[] = { 0,0 };
        while (it != intervals.end()) {
            if (over(newInterval, (*it), a) == 1) {
                intervals.insert(it--, newInterval);
                return intervals;
            }
            else if (over(newInterval, (*it), a) == 2) it++;
            else {
                intervals.erase(it);
                newInterval[0] = a[0];
                newInterval[1] = a[1];
            }
        }
        intervals.push_back(newInterval);
        return intervals;
    }
};