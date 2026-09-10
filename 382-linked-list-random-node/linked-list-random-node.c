typedef struct {
    struct ListNode* head;
} Solution;

Solution* solutionCreate(struct ListNode* head) {
    Solution* obj = malloc(sizeof(Solution));
    obj->head = head;
    return obj;
}

int solutionGetRandom(Solution* obj) {
    int result = obj->head->val;
    int count = 1;

    struct ListNode* curr = obj->head->next;

    while (curr != NULL) {
        count++;

        if (rand() % count == 0) {
            result = curr->val;
        }

        curr = curr->next;
    }

    return result;
}

void solutionFree(Solution* obj) {
    free(obj);
}