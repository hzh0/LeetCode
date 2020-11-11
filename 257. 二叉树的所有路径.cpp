/*
给定一个二叉树，返回所有从根节点到叶子节点的路径。

说明: 叶子节点是指没有子节点的节点。
*/

/*
简单的先序遍历然后存储起来路径上的值，最后将路径的值连接起来变成字符串储存起来即可
*/

/*
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
*/
class Solution {
public:
    vector<string> ans;
    vector<int> tem;
    vector<vector<int>> nums;

    void dfs(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            tem.push_back(root->val);
            nums.push_back(tem);
        }
        else {
            tem.push_back(root->val);
            if (root->left != nullptr) dfs(root->left);
            if (root->right != nullptr) dfs(root->right);
        }
        if (!tem.empty()) tem.pop_back();
    }

    void func() {
        for (auto& i : nums) {
            string s;
            for (auto& j : i) {
                s += to_string(j) + "->";
            }
            s.pop_back();
            s.pop_back();
            ans.push_back(s);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) return {};
        dfs(root);
        func();
        return ans;
    }
};