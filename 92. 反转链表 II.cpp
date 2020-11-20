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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        auto res = new ListNode(0);
        res->next = head;
        auto p = res;
        auto start = res, end = res;
        for (auto i = 0; i < m; ++i) {
            p = start;
            start = start->next;
        }
        auto pre = start->next;
        for (auto i = 0; i < n; ++i) end = end->next;
        end = end->next;
        while (start->next != end) {
            auto tem = p->next;
            p->next = pre;
            start->next=pre->next;
            pre->next = tem;
            pre = start->next;
        }
        return res->next;
    }
};