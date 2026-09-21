var superEggDrop = function(k, n) {
    let dp = new Array(k + 1).fill(0);
    let moves = 0;

    while (dp[k] < n) {
        moves++;

        for (let eggs = k; eggs >= 1; eggs--) {
            dp[eggs] = dp[eggs] + dp[eggs - 1] + 1;
        }
    }

    return moves;
};