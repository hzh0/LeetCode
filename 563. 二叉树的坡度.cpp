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

    int sum(TreeNode* root) {
        if (root == nullptr) return 0;
        return root->val + sum(root->left) + sum(root->right);
    }

    void func(TreeNode* root) {
        if (root == nullptr) return;
        root->val = abs(sum(root->left) - sum(root->right));
        func(root->left);
        func(root->right);
    }

    int findTilt(TreeNode* root) {
        func(root);
        return sum(root);
    }
};