/*
实现一个函数，检查一棵二叉树是否为二叉搜索树。
*/

/*
二叉搜索树的中序遍历是一个递增数列
中序遍历，若不满足递增顺序则为非法，否则为合法
*/

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

    TreeNode* pre = nullptr;
    bool isvalid = true;
    
    void ms(TreeNode* root) {
        if (root == nullptr) return;
        ms(root->left);
        if (pre != nullptr && root->val <= pre->val) {
            isvalid = false;
            return;
        }
        pre = root;
        ms(root->right);

    }

    bool isValidBST(TreeNode* root) {
        ms(root);
        return isvalid;
    }
};