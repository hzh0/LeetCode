/*struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};*/

// 递归的写法，胜在代码十分简洁明了
// 按顺序 先根再左右顺序迭代下去即可
class Solution {
public:
    vector<int> ans;

    void dlr(TreeNode* p) {
        if (p == nullptr) return;
        ans.push_back(p->val);
        dlr(p->left);
        dlr(p->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        dlr(root);
        return ans;
    }
};

// 迭代写法，用栈操作
// 每次操作将最顶端的值作为根拿出来处理，由于得到根后的处理顺序是先左后右，
// 所以接下来先将右结点放入栈中留着后面处理，然后放入左子树，使左子树在栈顶，方便下一轮优先处理
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        stack<TreeNode*> s;
        vector<int> ans;
        s.push(root);
        while (!s.empty()) {
            ans.push_back(s.top()->val);
            auto p = s.top();
            s.pop();
            if (p->right != nullptr) s.push(p->right);
            if (p->left != nullptr) s.push(p->left);
        }
        return ans;
    }
};