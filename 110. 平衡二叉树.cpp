/*
给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
*/

/*
计算每个结点的高度
然后判断每个结点是否平衡
*/

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
    // 计算结点高度
    int dp(TreeNode* root) {
        if (root==nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) return 1;
        return max(dp(root->left),dp(root->right)) + 1;
    }

    // 判断结点是否平衡
    bool ist(TreeNode* root) {
        if (root == nullptr) return true;
        return (abs(dp(root->left)-dp(root->right)) <= 1) && ist(root->left) && ist(root->right);
    }

    bool isBalanced(TreeNode* root) {
        return ist(root);
    }
};