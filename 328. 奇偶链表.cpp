/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) return head;
        auto ehead = head, ohead = head->next, t = ohead;

        while(t != nullptr && t->next != nullptr) {
            auto p = t->next, q = p->next;
            ehead->next = p;
            p->next =ohead;
            t->next = q;
            t = t->next;
            ehead = ehead->next;
        }
        return head;
    }
};