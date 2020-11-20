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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        auto p = root;
        int count = 0;
        while(p!=nullptr) {
            count++;
            p = p->next;
        }
        vector<ListNode*> ans;
        if (count < k) {
            while (root!= nullptr) {
                ans.push_back(root);
                root=root->next; 
                ans[ans.size()-1]->next = nullptr;             
            }
            for (auto i = 0; i < k-count; ++i) ans.push_back(nullptr);
            return ans;
        }
        int bas = count / k;
        int over = count % k;
        for (auto i = 0; i < over; ++i) {
            ans.push_back(root);
            for (auto j = 0; j < bas; ++j) {
                root = root->next;
            }
            auto p = root->next;
            root->next = nullptr;
            root = p;
        }
        for (auto i = 0; i < k - over; ++i) {
            ans.push_back(root);
            for (auto j = 0; j < bas-1; ++j) {
                root = root->next;
            }
            if(root != nullptr) {
                auto p = root->next;
                root->next = nullptr;
                root = p;    
            }
        } 
        return ans; 
    }
};