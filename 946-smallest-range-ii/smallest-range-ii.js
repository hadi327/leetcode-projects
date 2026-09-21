var smallestRangeII = function(nums, k) {
    nums.sort((a, b) => a - b);

    let n = nums.length;
    let answer = nums[n - 1] - nums[0];

    for (let i = 0; i < n - 1; i++) {
        let low = Math.min(
            nums[0] + k,
            nums[i + 1] - k
        );

        let high = Math.max(
            nums[i] + k,
            nums[n - 1] - k
        );

        answer = Math.min(answer, high - low);
    }

    return answer;
};