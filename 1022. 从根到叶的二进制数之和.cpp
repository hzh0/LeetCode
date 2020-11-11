/*
给出一棵二叉树，其上每个结点的值都是 0 或 1 。每一条从根到叶的路径都代表一个从最高有效位开始的二进制数。例如，如果路径为 0 -> 1 -> 1 -> 0 -> 1，那么它表示二进制数 01101，也就是 13 。

对树上的每一片叶子，我们都要找出从根到该叶子的路径所表示的数字。

以 10^9 + 7 为模，返回这些数字之和。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-root-to-leaf-binary-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


/*
跟 129 题一样的思路和方法，只不过这题是二进制，那道题是十进制而已
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
    vector<int> num;

    void getnum(TreeNode* root, int n) {
        if (root->left == nullptr && root->right == nullptr) {
            n = n*2 + root->val;
            num.push_back(n);
        }
        else {
            n = n*2 + root->val;
            if (root->left != nullptr)
                getnum(root->left, n);
            if (root->right != nullptr)
                getnum(root->right, n);
        }
        n /= 2;
    }


    int sumRootToLeaf(TreeNode* root) {
        int s = 0;
        getnum(root, s);
        int ans = 0;
        for (auto i : num) {
            ans += i;
        }
        return ans;       
    }
};