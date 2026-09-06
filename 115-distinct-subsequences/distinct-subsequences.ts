function numDistinct(s: string, t: string): number {
    const n = t.length;

    const dp: number[] = new Array(n + 1).fill(0);
    dp[0] = 1;

    for (const char of s) {
        // Go backwards so dp[j - 1] is still from the previous iteration
        for (let j = n; j >= 1; j--) {
            if (char === t[j - 1]) {
                dp[j] += dp[j - 1];
            }
        }
    }

    return dp[n];
}