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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        auto p = new ListNode(0), q = new ListNode(0);
        p->next = head;
        auto temp = p, temq = q;
        while (temp->next != nullptr) {
            if (temp->next->val >= x) {
                temq->next = temp->next;
                temp->next = temp->next->next;
                temq = temq->next;
            }
            else {
                temp = temp->next;
            }
        }
        temp->next = q->next;
        temq->next = nullptr;
        return p->next;
    }
};