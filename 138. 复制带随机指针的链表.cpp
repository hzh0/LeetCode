/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        auto p = head;
        while (p != nullptr) {
            auto q = new Node(p->val);
            q->next = p->next;
            p->next = q;
            p = p->next->next;
        }
        p = head;
        while (p != nullptr) {
            if (p->random != nullptr)
                p->next->random = p->random->next;
            else p->next->random = nullptr;
            p = p->next->next;
        }
        p = head;
        auto q = head->next;
        auto ans = q;
        while (p != nullptr) {
            p->next = p->next->next;
            if (q->next != nullptr)
                q->next = q->next->next;
            else q->next = nullptr;
            p = p->next;
            q = q->next;
        }
        return ans;      
    }
};