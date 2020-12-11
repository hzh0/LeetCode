class Solution {
public:
    string predictPartyVictory(string senate) {
        int size = senate.size();
        queue<int> R, D;
        for (auto i = 0; i < senate.size(); ++i) {
            if (senate[i] == 'R') R.push(i);
            else D.push(i);
        }

        while (!R.empty() && !D.empty()) {
            if (R.front() < D.front()) {
                D.pop();
                R.push(R.front()+size);
                R.pop();
            }
            else {
                R.pop();
                D.push(D.front()+size);
                D.pop();
            }
        }

        return D.empty() ? "Radiant" : "Dire";
    }
};