class Solution {
    public:
    int find(vector<int>& parent, int index) {
        if (parent[index] != index) {
            parent[index] = find(parent, parent[index]);
        }
        return parent[index];
    }

    void unions(vector<int>& parent, int index1, int index2) {
        parent[find(parent, index1)] = find(parent, index2); 
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int nodesCount = edges.size();
        vector<int> parent(nodesCount + 1);
        for (auto i = 1; i <= nodesCount; ++i) {
            parent[i] = i;
        }
        for (auto &i:edges) {
            int node1 = i[0], node2 = i[1];
            if (find(parent, node1) != find(parent, node2)) {
                unions(parent, node1, node2);   
            }
            else {
                return i;
            }
        }
        return {};
    }
};
