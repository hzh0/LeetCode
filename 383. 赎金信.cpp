class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        int a[26]{ 0 };
        for (auto& i : magazine) {
            a[i-'a']++;
        }
        for (auto& i : ransomNote) {
            if (a[i-'a'] == 0) {
                return false;
            }
            a[i-'a']--;
        }
        return true;
    }
};