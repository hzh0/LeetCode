/*
你需要采用前序遍历的方式，将一个二叉树转换成一个由括号和整数组成的字符串。

空节点则用一对空括号 "()" 表示。而且你需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/construct-string-from-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
按先序遍历遍历树，然后在遍历左右子树前加括号即可
当 左右子树 都为空 时，直接返回
当 左子树空 右子树非空 时，左子树所对应的空括号对不能省略
当 左子树非空 右子树空 时，右子树所对应的空括号对可以省略
*/

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
    string ans;
    void fs(TreeNode* t) {
        if (t== nullptr) return;
        ans += to_string(t->val);
        if (t->left == nullptr && t->right == nullptr) return;
        else if (t->left != nullptr && t->right == nullptr) {
            ans += '(';
            fs(t->left);
            ans += ')';
        }
        else{
            ans += '(';
            fs(t->left);
            ans += ')';
            ans += '(';
            fs(t->right);
            ans += ')';
        }
        
    }

    string tree2str(TreeNode* t) {
        if (t == nullptr) return "";
        fs(t);
        return ans;
    }
};