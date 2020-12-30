class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.size() == 1) {
            return stones[0];
        }

        sort(stones.begin(), stones.end());

        while (stones.size() > 1) {
            int size = stones.size();
            if (size == 2) {
                return stones[size - 1] == stones[size - 2] ? 0 : stones[size - 1] - stones[size - 2];
            }
            int tem = stones[size - 1] - stones[size - 2];
            if (tem == 0) {
                stones.pop_back();
                stones.pop_back();
            }
            else {
                for (auto i = size - 3; i >= 0; --i) {
                    if (tem > stones[i]) {
                        stones[i + 1] = tem;
                        stones.pop_back();
                        break;
                    }
                    if (tem <= stones[i] && i-1 >= 0 && tem >= stones[i-1] || i == 0) {
                        stones[i + 1] = stones[i];
                        stones[i] = tem;
                        stones.pop_back();
                        break;
                    }
                    else {
                        stones[i + 1] = stones[i];
                    }
                }
            }
        }
        return stones.size() ? stones[0] : 0;
    }
};