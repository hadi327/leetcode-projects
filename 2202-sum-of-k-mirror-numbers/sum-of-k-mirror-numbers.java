class Solution {
    public long kMirror(int k, int n) {
        long sum = 0;
        int count = 0;

        for (int len = 1; count < n; len++) {
            int halfLen = (len + 1) / 2;
            long start = pow10(halfLen - 1);
            long end = pow10(halfLen);

            for (long half = start; half < end && count < n; half++) {
                long num = makePalindrome(half, len % 2 == 1);

                if (isPalindromeBaseK(num, k)) {
                    sum += num;
                    count++;
                }
            }
        }

        return sum;
    }

    private long makePalindrome(long half, boolean oddLength) {
        long result = half;
        long x = oddLength ? half / 10 : half;

        while (x > 0) {
            result = result * 10 + x % 10;
            x /= 10;
        }

        return result;
    }

    private boolean isPalindromeBaseK(long num, int k) {
        long original = num;
        long reversed = 0;

        while (num > 0) {
            reversed = reversed * k + num % k;
            num /= k;
        }

        return original == reversed;
    }

    private long pow10(int exp) {
        long result = 1;

        while (exp-- > 0) {
            result *= 10;
        }

        return result;
    }
}