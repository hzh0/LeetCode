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
    int gethigh(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(gethigh(root->left), gethigh(root->right));
    }

    bool isBalanced(TreeNode* root) {
        return root == nullptr || (abs(gethigh(root->left) - gethigh(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right));
    }
};