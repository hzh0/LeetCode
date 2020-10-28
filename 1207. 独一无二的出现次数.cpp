/* 给你一个整数数组 arr，请你帮忙统计数组中每个数的出现次数。
 如果每个数的出现次数都是独一无二的，就返回 true；否则返回 false。*/

// 用一个 map 将数字和其出现的次数统计一下
// 然后将所有的 map 中存储的数字出现的次数放进一个 set 中
// 若有相同的次数，则 set 因其元素的唯一性，会造成 set 的 size 小于 map 的 size , 返回 false
// 如没有出现相同次数的数字，则 set 的 size 等于 map 的 size ，返回 true

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> m;
        set<int> s;
        for (auto i : arr) m[i]++;
        for (auto i : m) s.insert(i.second);
        return m.size() == s.size();
    }
};