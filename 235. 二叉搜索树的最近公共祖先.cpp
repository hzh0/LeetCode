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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int s = p->val > q->val ?  q->val:p->val;
        int l = (p->val + q->val) - s;
        int t = root->val;
        if (t < l && t > s) return root;
        if (t == q->val) return q;
        if (t == p->val) return p;
        if (t > l) return lowestCommonAncestor(root->left, p, q);
        return lowestCommonAncestor(root->right, p, q);   
    }
};