var combinationSum4 = function(nums, target) {
    const dp = new Array(target + 1).fill(0);
    dp[0] = 1;

    for (let sum = 1; sum <= target; sum++) {
        for (const num of nums) {
            if (sum >= num) {
                dp[sum] += dp[sum - num];
            }
        }
    }

    return dp[target];
};