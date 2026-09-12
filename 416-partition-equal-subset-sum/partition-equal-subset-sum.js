var canPartition = function(nums) {
    const total = nums.reduce((sum, num) => sum + num, 0);

    // If total is odd, we cannot split it equally
    if (total % 2 !== 0) {
        return false;
    }

    const target = total / 2;

    // dp[i] = whether we can make sum i
    const dp = new Array(target + 1).fill(false);
    dp[0] = true;

    for (const num of nums) {
        // Go backwards so each number is used only once
        for (let i = target; i >= num; i--) {
            dp[i] = dp[i] || dp[i - num];
        }
    }

    return dp[target];
};