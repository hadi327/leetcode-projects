class Solution {
    private String s;
    private Integer[][][][] memo;

    public int countSpecialNumbers(int n) {
        s = String.valueOf(n);
        int len = s.length();

        memo = new Integer[len][2][2][1 << 10];

        return dfs(0, 0, 1, 0) - 1;
    }

    private int dfs(int pos, int mask, int tight, int started) {
        if (pos == s.length()) {
            return 1;
        }

        if (memo[pos][tight][started][mask] != null) {
            return memo[pos][tight][started][mask];
        }

        int limit = tight == 1 ? s.charAt(pos) - '0' : 9;
        int answer = 0;

        for (int digit = 0; digit <= limit; digit++) {
            int newTight = (tight == 1 && digit == limit) ? 1 : 0;

            // Still leading zeros
            if (started == 0 && digit == 0) {
                answer += dfs(pos + 1, mask, newTight, 0);
            } else {
                // Digit already used
                if ((mask & (1 << digit)) != 0) {
                    continue;
                }

                answer += dfs(
                    pos + 1,
                    mask | (1 << digit),
                    newTight,
                    1
                );
            }
        }

        return memo[pos][tight][started][mask] = answer;
    }
}