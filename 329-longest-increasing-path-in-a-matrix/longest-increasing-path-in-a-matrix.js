var longestIncreasingPath = function(matrix) {
    const m = matrix.length;
    const n = matrix[0].length;

    const dp = Array.from(
        { length: m },
        () => Array(n).fill(0)
    );

    const directions = [
        [1, 0],
        [-1, 0],
        [0, 1],
        [0, -1]
    ];

    function dfs(r, c) {
        if (dp[r][c] !== 0) {
            return dp[r][c];
        }

        dp[r][c] = 1;

        for (const [dr, dc] of directions) {
            const nr = r + dr;
            const nc = c + dc;

            if (
                nr >= 0 && nr < m &&
                nc >= 0 && nc < n &&
                matrix[nr][nc] > matrix[r][c]
            ) {
                dp[r][c] = Math.max(
                    dp[r][c],
                    1 + dfs(nr, nc)
                );
            }
        }

        return dp[r][c];
    }

    let answer = 0;

    for (let r = 0; r < m; r++) {
        for (let c = 0; c < n; c++) {
            answer = Math.max(answer, dfs(r, c));
        }
    }

    return answer;
};