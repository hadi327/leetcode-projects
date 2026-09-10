long long maxRotateFunction(int* nums, int numsSize) {
    long long sum = 0;
    long long f = 0;

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        f += (long long)i * nums[i];
    }

    long long answer = f;

    for (int k = 1; k < numsSize; k++) {

        f = f + sum -
            (long long)numsSize * nums[numsSize - k];

        if (f > answer)
            answer = f;
    }

    return answer;
}