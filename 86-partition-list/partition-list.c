struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode before;
    struct ListNode after;

    struct ListNode* beforeCurrent = &before;
    struct ListNode* afterCurrent = &after;

    before.next = NULL;
    after.next = NULL;

    while (head != NULL) {
        if (head->val < x) {
            beforeCurrent->next = head;
            beforeCurrent = beforeCurrent->next;
        } else {
            afterCurrent->next = head;
            afterCurrent = afterCurrent->next;
        }

        head = head->next;
    }

    // End the second list
    afterCurrent->next = NULL;

    // Connect the two lists
    beforeCurrent->next = after.next;

    return before.next;
}