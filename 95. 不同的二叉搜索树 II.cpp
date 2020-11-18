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

    vector<TreeNode*> buildbs(int start, int end) {
        vector<TreeNode*> ans;
        if (start > end) {
            ans.push_back(nullptr);
            return ans;
        }  
        for (auto i = start; i <= end; ++i) {
            vector<TreeNode*> l = buildbs(start, i-1);
            vector<TreeNode*> r = buildbs(i+1, end);
            for (auto lt :l) {
                for (auto rt : r) {
                    auto p = new TreeNode(i);
                    p->left = lt;
                    p->right = rt;
                    ans.push_back(p);
                }
            }
        }
        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return buildbs(1, n);
    }
};