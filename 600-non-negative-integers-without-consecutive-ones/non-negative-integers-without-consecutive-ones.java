class Solution {
    public int findIntegers(int n) {
        int[] dp = new int[32];

        dp[0] = 1;
        dp[1] = 2;

        for (int i = 2; i < 32; i++)
            dp[i] = dp[i - 1] + dp[i - 2];

        int result = 0;
        int previousBit = 0;

        for (int i = 30; i >= 0; i--) {
            if ((n & (1 << i)) != 0) {
                result += dp[i];

                if (previousBit == 1)
                    return result;

                previousBit = 1;
            } else {
                previousBit = 0;
            }
        }

        return result + 1;
    }
}