class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);

        while (head) {
            ListNode* next = head->next;

            ListNode* current = &dummy;

            while (current->next &&
                   current->next->val < head->val) {
                current = current->next;
            }

            head->next = current->next;
            current->next = head;

            head = next;
        }

        return dummy.next;
    }
};