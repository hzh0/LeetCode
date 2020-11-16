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

    vector<int> tem;
    vector<vector<int>> ans;

    void dfs(TreeNode* root, int sum) {
        if (root == nullptr) return;
        tem.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr && root->val == sum) ans.push_back(tem);
        dfs(root->left, sum - root->val);
        dfs(root->right, sum - root->val);
        tem.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root, sum);
        return ans;
    }
};
