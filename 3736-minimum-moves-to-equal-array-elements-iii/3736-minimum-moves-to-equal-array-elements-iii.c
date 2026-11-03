int minMoves(int* nums, int numsSize) {
    int result=0, max=nums[0], i;

    /* Find the max. */
    for(i=0; i<numsSize; i++)
    { max=max>=nums[i]?max:nums[i]; }

    /* Calculate the result. */
    for(i=0; i<numsSize; i++)
    { result+=max-nums[i]; }

    return result;
}