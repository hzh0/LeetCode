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

    bool judge(TreeNode* s, TreeNode* t) {
        if (s == nullptr && t == nullptr) return true;
        if (s == nullptr && t != nullptr || s != nullptr && t == nullptr) return false;
        return s->val == t->val && judge(s->left, t->left) && judge(s->right, t->right);
    }

    bool dfs(TreeNode* s, int& num, TreeNode* t) {
        if (s == nullptr) {
            return false;
        }
        return judge(s, t) || dfs(s->left, num, t) || dfs(s->right, num, t);
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (t == nullptr) return true;
        if (s == nullptr) return false;
        int num = t->val;
        return dfs(s, num, t);
    }
};