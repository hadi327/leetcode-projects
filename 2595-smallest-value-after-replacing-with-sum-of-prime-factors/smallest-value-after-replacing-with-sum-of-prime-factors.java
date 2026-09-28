class Solution {
    public int smallestValue(int n) {
        while (true) {
            int sum = sumOfPrimeFactors(n);

            if (sum == n) {
                return n;
            }

            n = sum;
        }
    }

    private int sumOfPrimeFactors(int n) {
        int sum = 0;

        for (int p = 2; p * p <= n; p++) {
            while (n % p == 0) {
                sum += p;
                n /= p;
            }
        }

        if (n > 1) {
            sum += n;
        }

        return sum;
    }
}