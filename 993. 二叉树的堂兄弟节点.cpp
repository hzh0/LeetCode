/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        bool xf = false, yf = false;
        while(!q.empty()) {
            xf = false, yf = false;
            int size = q.size();
            for (auto i = 0; i < size; ++i) {
                if (q.front()->left && q.front()->right) {
                    if (q.front()->left->val == x) {
                        xf=true;
                        if (q.front()->right->val == y) return false;
                    }
                    else if (q.front()->left->val == y) {
                        yf = true;
                        if (q.front()->right->val == x) return false;
                    }
                    if (q.front()->right->val == x) {
                        xf=true;
                        if (q.front()->left->val == y) return false;
                    }
                    else if (q.front()->right->val == y) {
                        yf = true;
                        if (q.front()->left->val == x) return false;
                    }
                }
                else if (q.front()->left && !q.front()->right) {
                    if (q.front()->left->val == x) xf = true;
                    else if (q.front()->left->val == y) yf = true;
                }
                else if (!q.front()->left && q.front()->right) {
                    if (q.front()->right->val == x) xf = true;
                    else if (q.front()->right->val == y) yf = true;
                }
                if (xf && yf) return true;
                if (q.front()->left) q.push(q.front()->left);
                if (q.front()->right) q.push(q.front()->right);
                q.pop();
            }
        }
        return false;                
    }
};