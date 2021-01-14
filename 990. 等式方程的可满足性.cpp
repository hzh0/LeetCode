class Solution {
public:

    int Find(vector<int>& parents, int num) {
        if (parents[num] != num) {
            parents[num] = Find(parents, parents[num]);
        }   
        return parents[num]; 
    }

    void Union(vector<int>& parents, int index1, int index2) {
        if (Find(parents, index1) != Find(parents, index2)) {
            parents[Find(parents,index1)] = Find(parents, index2);
        }
    }

    bool equationsPossible(vector<string>& equations) {
        vector<int> parents(26,0);
        for (auto i = 0; i < 26; ++i) {
            parents[i] = i;
        }
        vector<string> v;
        for (auto& i : equations) {
            if (i[1] == '!') {
                v.push_back(i);   
            }
            else {
                Union(parents, i[0]-'a', i[3]-'a');
            }
        }
        for (auto&i : v) {
            if (Find(parents, i[0]-'a') == Find(parents, i[3]-'a')) {
                return false;
            }
        }
        return true;
    }
};