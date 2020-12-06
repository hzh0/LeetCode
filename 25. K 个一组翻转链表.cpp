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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1) return head;
        auto cur = head;
        int index = 0;
        auto ans = head;
        auto pre = cur;
        while (true) {
            auto p = cur;
            for (auto i = 0; i < k - 1; ++i) {
                if (p == nullptr) return ans;
                p = p->next;   
                if (p == nullptr) return ans;          
            }
            auto start = cur;
            while (p != start) {
                auto q = cur->next;
                cur->next = q->next;
                q->next = start;
                start = q;
            }
            if (index != 0) pre->next = start;
            pre = cur;
            cur = cur->next;
            index++;
            if (index == 1) ans = start;
        }
        return ans;
    }
};