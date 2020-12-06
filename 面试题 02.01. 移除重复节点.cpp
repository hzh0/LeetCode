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
    ListNode* removeDuplicateNodes(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        map<int, int> m;
        auto pre = head;
        m[head->val]++;
        auto p = pre->next;
        while (p != nullptr) {
            if (m[p->val]) {
                pre->next = p->next;
            } 
            else {
                m[p->val]++;
                pre = pre->next;
            }
            p = p->next;
        }
        return head;
    }
};