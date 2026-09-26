class Solution {
    private static final long MOD = 1_000_000_007L;

    public int countTexts(String pressedKeys) {
        int n = pressedKeys.length();

        long[] dp = new long[n + 1];
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            char digit = pressedKeys.charAt(i - 1);

            int limit = (digit == '7' || digit == '9') ? 4 : 3;

            for (int len = 1; len <= limit && i - len >= 0; len++) {
                if (pressedKeys.charAt(i - len) != digit) {
                    break;
                }

                dp[i] = (dp[i] + dp[i - len]) % MOD;
            }
        }

        return (int) dp[n];
    }
}