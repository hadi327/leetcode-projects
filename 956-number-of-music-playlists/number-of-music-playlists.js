var numMusicPlaylists = function(n, goal, k) {
    const MOD = 1000000007;

    let dp = Array.from(
        { length: goal + 1 },
        () => new Array(n + 1).fill(0)
    );

    dp[0][0] = 1;

    for (let i = 1; i <= goal; i++) {
        for (let j = 1; j <= Math.min(i, n); j++) {

            // Add a new unique song
            dp[i][j] =
                dp[i - 1][j - 1] *
                (n - j + 1);

            // Replay an existing song
            if (j > k) {
                dp[i][j] +=
                    dp[i - 1][j] * (j - k);
            }

            dp[i][j] %= MOD;
        }
    }

    return dp[goal][n];
};