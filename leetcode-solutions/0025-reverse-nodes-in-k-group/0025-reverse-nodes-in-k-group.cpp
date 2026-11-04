
class Solution {
public:
    int findLength(ListNode* head) {
        int length = 0;
        while (head) {
            length++;
            head = head->next;
        }
        return length;
    }

    ListNode* reverse(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (k--) {
            ListNode* next1 = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next1;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1 || head == nullptr) {
            return head;
        }

        int n = findLength(head);
        ListNode dummy(0, head);
        ListNode* groupPrev = &dummy;

        while (n >= k) {
            ListNode* groupHead = groupPrev->next;
            ListNode* curr = groupHead;
            
            for (int i = 0; i < k; i++) {
                curr = curr->next;
            }

            ListNode* nextGroup = curr;

            ListNode* prev = nextGroup;
            curr = groupHead;

            for (int i = 0; i < k; i++) {
                ListNode* next1 = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next1;
            }

            groupPrev->next = prev;
            groupPrev = groupHead;
            n -= k;
        }

        return dummy.next;
    }
};
