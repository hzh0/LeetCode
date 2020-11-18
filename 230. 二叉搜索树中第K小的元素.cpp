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
    int index = 1, max = 0;

    void func(TreeNode* root, int k) {
        if (root == nullptr) return;
        func(root->left, k);
        if (index == k) {
            max = root->val;
            index++;
            return;
        }
        else index++;
        func(root->right, k);
    }


    int kthSmallest(TreeNode* root, int k) {
        func(root, k);
        return max;
    }
};