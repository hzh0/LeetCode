/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:

    void func(Node* n) {
        if (n == nullptr) return;
        if (n->left != nullptr) {
            if (n->right != nullptr) n->left->next = n->right;
            else {
                auto p = n->next;
                bool flag = false;
                while(p != nullptr) {
                    if (p->left != nullptr) {
                        n->left->next = p->left;
                        flag = true;
                        break;
                    }
                    if (p->right != nullptr) {
                        n->left->next = p->right;
                        flag = true;
                        break;
                    }
                    p=p->next;
                }
                if (!flag) n->left->next = nullptr;
            }
        }
        if (n->right != nullptr) {
            auto p = n->next;
            bool flag = false;
            while(p != nullptr) {
                if (p->left != nullptr) {
                    n->right->next = p->left;
                    flag = true;
                    break;
                }
                if (p->right != nullptr) {
                    n->right->next = p->right;
                    flag = true;
                    break;
                }
                p=p->next;
            }
            if (!flag) n->right->next = nullptr;
        }
        func(n->right);
        func(n->left);
        
    }

    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;
        func(root);
        return root;
    }
};