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

    int ans = 0;

    void dfs(TreeNode* root, int num) {
        if (root->val == num) {
            ans++;
        }
        if (root->left != nullptr) dfs(root->left, num-root->val);
        if (root->right != nullptr) dfs(root->right, num-root->val);
    }

    void ddfs(TreeNode* root, int num) {
        if (root == nullptr) return;
        dfs(root, num);
        ddfs(root->left, num);
        ddfs(root->right, num);
    }

    int pathSum(TreeNode* root, int sum) {
        ddfs(root, sum);
        return ans;
    }
};