/*
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
*/

/*
对于字符串中的每个字符串 str , 我们 sort 一下，那么所有的异位词因为包含完全相同但不同序的字母，排完序后都会是一样的
例如 "eat","tea","ate" 来说，sort 完都是 "aet"，因此我们可以使用 map< string , vector<string> >, key 为排完序的str,而value就是那些排序前的异位词
如上面的例子则会有 m["aet"] = {"eat","tea","ate"}
最后遍历一遍 map 将所有的 value 加入结果返回即可
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string, vector<string>> m;
        for (auto i : strs) {
            string str = i;
            sort(str.begin(), str.end());
            m[str].push_back(i);
        }
        for (auto i : m) res.push_back(i.second);
        return res;
    }
};