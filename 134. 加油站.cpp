class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cur = 0;
        int start = 0;
        for (auto i = 0; i < gas.size(); ++i) {
            if (gas[i] >= cost[i]) {
                start = i;
                cur = gas[i] - cost[i];
                int index = i + 1;
                if (index == gas.size()) index = 0;
                while (index != start) { 
                    if (cur + gas[index] < cost[index]) break;
                    else {
                        cur = cur + gas[index] - cost[index];
                        index++;
                        if (index == gas.size()) index = 0;
                    }
                }
                if (index == start) return start;
            }
        }
        return -1;
    }
};