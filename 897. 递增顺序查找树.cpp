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
    TreeNode* pre = new TreeNode(0);
    
    void func(TreeNode* t) {
        if (!t) return;
        func(t->left);
        pre->right = t;
        pre->left = nullptr;
        pre = t;
        func(t->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        auto head = pre;
        func(root);
        return head->right;
    }
};