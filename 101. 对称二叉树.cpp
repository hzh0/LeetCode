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

    bool func(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return true;
        if (root1 == nullptr && root2!=nullptr || root1!=nullptr && root2==nullptr) return false;
        if (root1->val != root2->val) return false;
        return func(root1->left,root2->right) && func(root1->right, root2->left);
        
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return func(root->left,root->right);
            
    }
};