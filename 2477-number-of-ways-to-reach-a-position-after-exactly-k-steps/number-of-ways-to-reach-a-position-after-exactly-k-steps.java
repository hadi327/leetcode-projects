class Solution {
    static final long MOD = 1_000_000_007L;

    public int numberOfWays(int startPos, int endPos, int k) {
        int distance = Math.abs(endPos - startPos);

        if (distance > k || (k - distance) % 2 != 0) {
            return 0;
        }

        int right = (k + endPos - startPos) / 2;

        long[] dp = new long[k + 1];
        dp[0] = 1;

        for (int i = 1; i <= k; i++) {
            for (int j = i; j >= 1; j--) {
                dp[j] = (dp[j] + dp[j - 1]) % MOD;
            }
        }

        return (int) dp[right];
    }
}