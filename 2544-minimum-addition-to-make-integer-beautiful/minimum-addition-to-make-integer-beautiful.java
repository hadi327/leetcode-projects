class Solution {
    public long makeIntegerBeautiful(long n, int target) {
        long original = n;
        long place = 1;

        while (digitSum(n) > target) {
            long digit = (n / place) % 10;

            if (digit != 0) {
                n += (10 - digit) * place;
            }

            place *= 10;
        }

        return n - original;
    }

    private long digitSum(long n) {
        long sum = 0;

        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }
}