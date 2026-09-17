class Solution {
    static final int MOD = 1_000_000_007;

    public int checkRecord(int n) {
        // dp[a][l]:
        // a = number of absences (0 or 1)
        // l = consecutive late days (0, 1, 2)

        long[][] dp = new long[2][3];
        dp[0][0] = 1;

        for (int day = 0; day < n; day++) {
            long[][] next = new long[2][3];

            for (int a = 0; a <= 1; a++) {
                for (int l = 0; l <= 2; l++) {
                    long value = dp[a][l];

                    // Present
                    next[a][0] = (next[a][0] + value) % MOD;

                    // Late
                    if (l < 2)
                        next[a][l + 1] =
                            (next[a][l + 1] + value) % MOD;

                    // Absent
                    if (a < 1)
                        next[a + 1][0] =
                            (next[a + 1][0] + value) % MOD;
                }
            }

            dp = next;
        }

        long result = 0;

        for (int a = 0; a <= 1; a++) {
            for (int l = 0; l <= 2; l++) {
                result = (result + dp[a][l]) % MOD;
            }
        }

        return (int) result;
    }
}