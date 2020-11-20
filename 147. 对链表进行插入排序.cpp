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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        auto ans = new ListNode(0);
        ans->next = head;
        auto res = ans;
        auto p = head, pre = head, q = pre->next;
        while (q!= nullptr) {
            if (q->val > pre->val) {
                pre = pre->next;
                q = q->next;
            }
            else {
                while (p->val < q->val) {
                    p = p->next;
                    ans = ans->next;
                }
                pre->next = q->next;
                ans->next = q;
                q->next = p;
                ans = res;
                p = ans->next;
                q = pre->next;

            }
        }
        return res->next;

    }
};