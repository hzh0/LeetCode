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

    int depth(TreeNode* r) {
        if (r == nullptr) return 0;
        else return 1 + max(depth(r->left), depth(r->right));
    }

    int countNodes(TreeNode* root) { 
        if (root == nullptr) return 0;   
        if (depth(root->left) == depth(root->right)) return pow(2,depth(root->left))-1 + 1 + countNodes(root->right);
        if (depth(root->left) > depth(root->right)) return pow(2,depth(root->right))-1 + 1 + countNodes(root->left);   
        return 0;
    }
};