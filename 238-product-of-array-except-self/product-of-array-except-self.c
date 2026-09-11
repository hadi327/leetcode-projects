/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* ans = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    int left = 1;

    // Store product of everything to the left
    for (int i = 0; i < numsSize; i++) {
        ans[i] = left;
        left *= nums[i];
    }

    int right = 1;

    // Multiply by product of everything to the right
    for (int i = numsSize - 1; i >= 0; i--) {
        ans[i] *= right;
        right *= nums[i];
    }

    return ans;
}