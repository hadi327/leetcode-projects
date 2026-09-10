typedef struct {
    int* nums;
    int size;
} Solution;

Solution* solutionCreate(int* nums, int numsSize) {
    Solution* obj = malloc(sizeof(Solution));

    obj->nums = nums;
    obj->size = numsSize;

    return obj;
}

int solutionPick(Solution* obj, int target) {
    int answer = -1;
    int count = 0;

    for (int i = 0; i < obj->size; i++) {

        if (obj->nums[i] == target) {
            count++;

            if (rand() % count == 0)
                answer = i;
        }
    }

    return answer;
}

void solutionFree(Solution* obj) {
    free(obj);
}