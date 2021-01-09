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
    int ans = 0;
    map<TreeNode*, int> ml;
    map<TreeNode*, int> mr;
    void dfs(TreeNode* root) {
        if (root == nullptr) {
            ml[root] = -1;
            mr[root] = -1;
            return;
        }
        dfs(root->left);
        dfs(root->right);
        mr[root] = ml[root->right] + 1;
        ml[root] = mr[root->left]+1;
        if (mr[root] > ans) {
            ans = mr[root];
        }
        if (ml[root] > ans) {
            ans = ml[root];
        }
    }

    int longestZigZag(TreeNode* root) {
        dfs(root);
        return ans;
    }
};

class Solution {
public:
    int ans = 0;

    int dfs(TreeNode* root, bool left) {
        if (root == nullptr) return 0;
        int l = dfs(root->left, true);
        int r = dfs(root->right, false);
        int big = l > r ? l : r;
        if (big > ans) {
            ans = big;
        }
        if (left) {
            return r+1;
        }
        return l+1;
    }


    int longestZigZag(TreeNode* root) {
        dfs(root, true);
        return ans;
    }
};