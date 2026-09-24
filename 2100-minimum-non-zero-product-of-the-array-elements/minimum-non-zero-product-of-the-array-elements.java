class Solution {
    static final long MOD = 1_000_000_007L;

    public int minNonZeroProduct(int p) {
        long m = (1L << p) - 1;

        long base = m - 1;
        long exponent = (m - 1) / 2;

        long result = modPow(base, exponent);

        result = result * (m % MOD) % MOD;

        return (int) result;
    }

    private long modPow(long base, long exponent) {
        long result = 1;

        base %= MOD;

        while (exponent > 0) {
            if ((exponent & 1) == 1) {
                result = result * base % MOD;
            }

            base = base * base % MOD;
            exponent >>= 1;
        }

        return result;
    }
}