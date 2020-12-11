class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int money[2]{ 0 };
        for (auto& i : bills) {
            if (i == 5) money[0]++;
            else if (i == 10) {
                if (money[0] == 0) return false;
                money[0]--;
                money[1]++;
            }
            else {
                if (money[1] != 0 && money[0] != 0) {
                    money[0]--;
                    money[1]--;
                }
                else if (money[1] == 0) {
                    if (money[0] < 3) return false;
                    else money[0] -= 3;
                }
                else return false;
            }
        }
        return true;
    }
};