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
    vector<int> nextLargerNodes(ListNode* head) {
        stack < pair<int, int>> s;
        vector<int> ans;
        int index = 0;
        while (head != nullptr) {
            ans.push_back(0);
            if (!s.empty()) {
                while (!s.empty() && head->val > s.top().first) {
                    ans[s.top().second] = head->val;
                    s.pop();
                }
            }
            s.push(make_pair(head->val, index));
            index++;
            head = head->next;
        }
        while (!s.empty()) {
            ans[s.top().second] = 0;
            s.pop();
        }
        return ans;
    }
};