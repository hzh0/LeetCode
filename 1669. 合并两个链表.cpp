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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        auto p = list1;
        for (auto i = 0; i < a - 1; ++i) p = p->next;
        auto q = p;
        for (auto i = 0; i < b - a + 2; ++i) q = q->next;
        p->next = list2;
        p = list2;
        while (p->next != nullptr) p = p->next;
        p->next = q;
        return list1;
    }
};