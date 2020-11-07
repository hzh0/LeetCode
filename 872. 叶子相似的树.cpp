/*
请考虑一棵二叉树上所有的叶子，这些叶子的值按从左到右的顺序排列形成一个 叶值序列 。
*/

/*
遍历查看两颗树的叶子结点序列是否相同即可
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

    vector<int> v1;
    vector<int> v2;

    void func(TreeNode* root, vector<int>& v) {
        if (root == nullptr) return;
        else if (root->left == nullptr && root->right == nullptr) v.push_back(root->val);
        else {
            func(root->left, v);
            func(root->right, v);
        }
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        func(root1, v1);
        func(root2, v2);
        return v1 == v2;   
    }
};

