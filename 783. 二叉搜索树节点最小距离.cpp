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
    int ans = INT_MAX;

    void func(TreeNode* root) {
        if (root == nullptr) return;
        func(root->left);
        if(pre != -1) ans = min(ans,abs(root->val-pre));
        pre = root->val;
        func(root->right);
    }

    int minDiffInBST(TreeNode* root) {
        if (root == nullptr) return 0;
        func(root);
        return ans;
    }
};