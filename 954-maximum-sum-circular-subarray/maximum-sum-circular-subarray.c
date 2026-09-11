int maxSubarraySumCircular(int* nums, int numsSize) {
    int total = 0;

    int currentMax = 0;
    int maxSum = nums[0];

    int currentMin = 0;
    int minSum = nums[0];

    for (int i = 0; i < numsSize; i++) {
        total += nums[i];

        // Kadane's algorithm for maximum subarray
        currentMax = (currentMax > 0)
                   ? currentMax + nums[i]
                   : nums[i];

        if (currentMax > maxSum)
            maxSum = currentMax;

        // Kadane's algorithm for minimum subarray
        currentMin = (currentMin < 0)
                   ? currentMin + nums[i]
                   : nums[i];

        if (currentMin < minSum)
            minSum = currentMin;
    }

    // If all numbers are negative
    if (maxSum < 0)
        return maxSum;

    // Maximum wrapping sum
    int circularSum = total - minSum;

    return maxSum > circularSum ? maxSum : circularSum;
}