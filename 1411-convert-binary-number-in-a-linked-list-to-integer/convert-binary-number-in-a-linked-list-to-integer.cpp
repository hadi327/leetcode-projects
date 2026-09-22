class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int answer = 0;

        while (head != nullptr) {
            answer = answer * 2 + head->val;
            head = head->next;
        }

        return answer;
    }
};