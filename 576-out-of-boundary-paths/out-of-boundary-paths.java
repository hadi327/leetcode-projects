class Solution {
    static final int MOD = 1_000_000_007;

    public int findPaths(int m, int n, int maxMove,
                         int startRow, int startColumn) {

        long[][] dp = new long[m][n];
        dp[startRow][startColumn] = 1;

        long result = 0;

        int[] dr = {-1, 1, 0, 0};
        int[] dc = {0, 0, -1, 1};

        for (int move = 0; move < maxMove; move++) {
            long[][] next = new long[m][n];

            for (int r = 0; r < m; r++) {
                for (int c = 0; c < n; c++) {
                    if (dp[r][c] == 0)
                        continue;

                    for (int k = 0; k < 4; k++) {
                        int nr = r + dr[k];
                        int nc = c + dc[k];

                        if (nr < 0 || nr >= m ||
                            nc < 0 || nc >= n) {
                            result = (result + dp[r][c]) % MOD;
                        } else {
                            next[nr][nc] =
                                (next[nr][nc] + dp[r][c]) % MOD;
                        }
                    }
                }
            }

            dp = next;
        }

        return (int) result;
    }
}