var distinctSubseqII = function(s) {
    const MOD = 1000000007;

    // dp[i] = number of distinct subsequences
    // using the first i characters
    let dp = 1;

    // Store the contribution of each character
    const last = new Array(26).fill(0);

    for (let i = 0; i < s.length; i++) {
        const c = s.charCodeAt(i) - 97;

        const newDp = (2 * dp - last[c] + MOD) % MOD;

        last[c] = dp;
        dp = newDp;
    }

    // Remove the empty subsequence
    return (dp - 1 + MOD) % MOD;
};