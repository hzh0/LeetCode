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
    int min = INT_MAX;
    int num = 0;

    void thro(TreeNode* n) {
        num++;
        if (n->left == nullptr && n->right == nullptr) {
            min = min < num ? min:num;
        }
        else {
            if (n->left) thro(n->left);
            if (n->right) thro(n->right);
        }
        num--;
    }

    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        thro(root);
        return min;
    }
};