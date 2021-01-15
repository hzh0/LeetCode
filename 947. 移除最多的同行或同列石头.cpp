class Solution {
public:

    map<int, int> parents;
    int count = 0;

    int Find(int index) {
        if (parents.count(index) == 0) {
            parents[index] = index;
            count++;
        }
        if (parents[index] != index) {
            parents[index] = Find(parents[index]);
        }
        return parents[index];
    }

    void Union(int index1, int index2) {
        int root1 = Find(index1);
        int root2 = Find(index2);
        if (root1 == root2) {
            return;
        }
        parents[root1] = root2;
        count--;
    }

    int removeStones(vector<vector<int>>& stones) {
        for (auto& i : stones) {
            Union(i[0]+10001, i[1]);
        }    
        return stones.size() - count;
    }
};