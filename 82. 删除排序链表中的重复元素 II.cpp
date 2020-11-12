/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    void remove(ListNode* ln) {
        if (ln == nullptr) return;
        if (ln->next != nullptr && ln->next->next != nullptr) {
            auto p = ln->next;
            auto q = p->next;
            bool flag = false;
            while(p->val == q->val) {
                p->next = q->next;
                q = p->next;
                if (q==nullptr) {
                    ln->next = p->next;
                    return;    
                }
                flag = true;
            }
            if (flag) {
                ln->next = p->next;
                remove(ln);
            }
            else {
                remove(ln->next);
            }
        }
    }

    ListNode* deleteDuplicates(ListNode* head) {
        auto p = new ListNode(0);
        p->next = head;
        remove(p);
        return p->next;
    }
};