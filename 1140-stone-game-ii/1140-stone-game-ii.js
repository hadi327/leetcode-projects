var stoneGameII = function(piles) {
    const n = piles.length;

    // suffix[i] = sum of piles from i to n-1
    const suffix = new Array(n + 1).fill(0);

    for (let i = n - 1; i >= 0; i--) {
        suffix[i] = suffix[i + 1] + piles[i];
    }

    const dp = Array.from(
        { length: n },
        () => new Array(n + 1).fill(-1)
    );

    function solve(i, M) {
        if (i >= n) return 0;

        if (dp[i][M] !== -1) {
            return dp[i][M];
        }

        // Can take all remaining piles
        if (2 * M >= n - i) {
            return dp[i][M] = suffix[i];
        }

        let best = 0;

        // Take X piles, where 1 <= X <= 2M
        for (let X = 1; X <= 2 * M; X++) {
            const opponent = solve(i + X, Math.max(M, X));

            // Current player gets remaining total
            // minus what opponent can get.
            best = Math.max(
                best,
                suffix[i] - opponent
            );
        }

        return dp[i][M] = best;
    }

    return solve(0, 1);
};