class Solution {
    static final long MOD = 1_000_000_007L;

    public int numberOfGoodSubsets(int[] nums) {
        int[] freq = new int[31];

        for (int x : nums) {
            freq[x]++;
        }

        // Prime factors for numbers 2..30
        int[] primes = {
            2, 3, 5, 7, 11,
            13, 17, 19, 23, 29
        };

        int[] mask = new int[31];

        for (int x = 2; x <= 30; x++) {
            int value = x;

            for (int i = 0; i < primes.length; i++) {
                int p = primes[i];
                int count = 0;

                while (value % p == 0) {
                    value /= p;
                    count++;
                }

                // Repeated prime factor -> invalid
                if (count >= 2) {
                    mask[x] = -1;
                    break;
                }

                if (count == 1) {
                    mask[x] |= (1 << i);
                }
            }
        }

        int totalMasks = 1 << 10;

        long[] dp = new long[totalMasks];
        dp[0] = 1;

        for (int x = 2; x <= 30; x++) {
            if (freq[x] == 0 || mask[x] == -1)
                continue;

            int m = mask[x];

            // Go backwards so each x is used at most once
            // as a distinct value.
            for (int state = totalMasks - 1; state >= 0; state--) {
                if ((state & m) != 0)
                    continue;

                int next = state | m;

                dp[next] = (dp[next]
                        + dp[state] * freq[x]) % MOD;
            }
        }

        long ans = 0;

        for (int state = 1; state < totalMasks; state++) {
            ans = (ans + dp[state]) % MOD;
        }

        // Every good subset can contain any subset of the 1s.
        // There are 2^freq[1] possibilities.
        long ones = modPow(2, freq[1]);

        ans = ans * ones % MOD;

        return (int) ans;
    }

    private long modPow(long base, long exp) {
        long result = 1;

        while (exp > 0) {
            if ((exp & 1) == 1)
                result = result * base % MOD;

            base = base * base % MOD;
            exp >>= 1;
        }

        return result;
    }
}