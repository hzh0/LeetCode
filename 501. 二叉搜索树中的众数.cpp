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

    bool firsttime = true;
    vector<int> ans;
    int count = 1;
    int maxcount = -1;
    long long pre;

    void dfs(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        dfs(root->left);
        if (firsttime) {
            pre = (long long)root->val + 1 > 2147483648 ? root->val + 1 : (long long)root->val-1;
            firsttime = false;
        }
        if (root->val == pre) {
            count++;
        }
        else {
            count = 1;
        }
        if (count > maxcount) {
            ans.clear();
            ans.push_back(root->val);
            maxcount = count;
        }
        else if (count == maxcount) {
            ans.push_back(root->val);
        }
        pre = root->val;
        dfs(root->right);
    }


    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return ans;
    }
};