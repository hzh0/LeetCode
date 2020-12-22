/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return{};
        int level = 1;
        deque<TreeNode*> q;
        q.push_back(root);
        vector<vector<int>> ans;
        while (!q.empty()) {
            int size = q.size() - 1;
            int count = size;
            vector<int> v(size+1, 0);
            for (auto i = 0; i <= count; ++i) {
                if (level % 2) {
                    v[i] = q.front()->val;
                }
                else {
                    v[size - i] = q.front()->val;
                }
                if (q.front()->left != nullptr) q.push_back(q.front()->left);
                if (q.front()->right != nullptr) q.push_back(q.front()->right);
                q.pop_front();
            }
            ans.push_back(v);
            level++;
        }
        return ans;
    }
};