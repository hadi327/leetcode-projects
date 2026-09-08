var missingNumber = function(nums) {
    let result = nums.length;

    for (let i = 0; i < nums.length; i++) {
        result ^= i;
        result ^= nums[i];
    }

    return result;
};