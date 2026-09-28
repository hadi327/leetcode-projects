class Solution {
    public int[] closestPrimes(int left, int right) {
        int prev = -1;
        int bestA = -1;
        int bestB = -1;
        int minDiff = Integer.MAX_VALUE;

        for (int num = left; num <= right; num++) {
            if (isPrime(num)) {
                if (prev != -1 && num - prev < minDiff) {
                    minDiff = num - prev;
                    bestA = prev;
                    bestB = num;
                }

                prev = num;
            }
        }

        return new int[]{bestA, bestB};
    }

    private boolean isPrime(int n) {
        if (n < 2) return false;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }
}