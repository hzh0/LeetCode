/*
给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。
*/

/*
二叉搜索树的中序排列是递增的，因此差绝对值最小的一定是中序遍历相邻两结点
因此用一个变量pre记住上一个结点，然后用当前结点与pre做差，最后记录最小的结果即可
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
    int pre = -1;
    int min = INT_MAX;
    void inorder(TreeNode* n) {
        if (n == nullptr) return;
        inorder(n->left);
        if (pre < 0) pre = n->val;
        else {
            min = min < abs(n->val - pre) ? min : abs(n->val - pre);
            pre = n->val;
        }
        inorder(n->right);
    }

    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return min;
    }
};