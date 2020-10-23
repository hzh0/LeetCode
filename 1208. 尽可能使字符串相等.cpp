// 滑动窗口
// i 为左边下标，j 为右边下表
// 1. 通过不断右移增加新的字符到窗口中，给定的费用将逐渐减少
// 2. 当费用减少至不够用时，从窗口左边删除字符，费用随之增加
// 3. 当费用增至可以再添加字符时，回到第 1 步继续执行，知道遍历完所有字符为止
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i = 0, j = 0;
        int ans = 0;
        while (j < s.size()) {
            while (abs(s[j]-t[j]) <= maxCost && j < s.size()) {
                maxCost -= abs(s[j]-t[j]);
                j++;
            }   
            ans = max(ans, j-i);            
            maxCost += abs(s[i]-t[i]);
            i++;
        }        
        return ans;
    }
};