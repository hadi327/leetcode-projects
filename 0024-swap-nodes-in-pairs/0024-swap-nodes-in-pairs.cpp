class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* second = head->next;

        head->next = swapPairs(second->next);
        second->next = head;

        return second;
    }
};