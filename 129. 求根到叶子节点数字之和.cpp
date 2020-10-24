/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 从根往下遍历，直到叶子节点时将数字储存起来，从某个节点返回回退时记得减去该结点的值
// 最后将所有值加起来即可
class Solution {
public:
    vector<int> num;

    void getnum(TreeNode* root, int n) {
        if (root->left == nullptr && root->right == nullptr) {
            n = n * 10 + root->val;
            num.push_back(n);
        }
        else {
            n = n * 10 + root->val;
            if (root->left != nullptr)
                getnum(root->left, n);
            if (root->right != nullptr)
                getnum(root->right, n);
        }
        n = n / 10;
    }

    int sumNumbers(TreeNode* root) {
        if (root == nullptr) return 0;
        getnum(root, 0);
        int ans = 0;
        for (auto i : num) {
            ans += i;
        }
        return ans;
    }
};