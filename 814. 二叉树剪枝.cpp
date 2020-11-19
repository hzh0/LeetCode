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
    void func(TreeNode* root) {
        if (root == nullptr) return;
        func(root->left);
        func(root->right);
        if (root->left != nullptr && root->left->val == 0 && root->left->left == nullptr && root->left->right == nullptr) root->left =nullptr; 
        if (root->right != nullptr && root->right->val == 0 && root->right->left == nullptr && root->right->right == nullptr) root->right =nullptr; 
    }

    TreeNode* pruneTree(TreeNode* root) {
        func(root);
        if (root->val == 0 && root->left == nullptr && root->right == nullptr) return nullptr;
        return root;
    }
};