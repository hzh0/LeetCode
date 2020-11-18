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

    map<int,int> m;
    int count = 1;
    vector<int> v;

    int sum(TreeNode* root) {
        if (root == nullptr) return 0;
        int num = root->val + sum(root->left)+sum(root->right);
        m[num]++;
        if (m[num] == count) v.push_back(num);
        if (m[num] > count) {
            count = m[num];
            v.clear();
            v.push_back(num);
        }
        return num;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        sum(root);
        return v;
    }
};