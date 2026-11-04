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
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> values;
        for (ListNode* head : lists) {
            ListNode* current = head;
            while (current != nullptr) {
                values.push_back(current->val);
                current = current->next;
            }
        }
        sort(values.begin(), values.end());
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        for (int value : values) {
            tail->next = new ListNode(value);
            tail = tail->next;
        }
        return dummy->next;
    }
};