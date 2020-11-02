/*
给定两个数组，编写一个函数来计算它们的交集。
*/

/*
用两个 set 将两个数组的数字存储起来，减少重复数字的影响
然后遍历两个 set 查找相同数字即可
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1, s2;
        for (auto i : nums1) s1.insert(i);  
        for (auto i : nums2) s2.insert(i);
        vector<int> v;
        for (auto i : s1) {
            for (auto j : s2) {
                if (i == j) v.push_back(i);
            }
        }
        return v;  
    }
};