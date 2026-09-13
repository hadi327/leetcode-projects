var getMoneyAmount = function(n) {
    const dp = Array.from(
        { length: n + 2 },
        () => new Array(n + 2).fill(0)
    );

    for (let length = 2; length <= n; length++) {
        for (let left = 1; left + length - 1 <= n; left++) {
            const right = left + length - 1;
            dp[left][right] = Infinity;

            for (let guess = left; guess <= right; guess++) {
                const cost =
                    guess +
                    Math.max(
                        guess > left ? dp[left][guess - 1] : 0,
                        guess < right ? dp[guess + 1][right] : 0
                    );

                dp[left][right] =
                    Math.min(dp[left][right], cost);
            }
        }
    }

    return dp[1][n];
};