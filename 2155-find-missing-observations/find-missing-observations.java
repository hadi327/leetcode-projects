class Solution {
    public int[] missingRolls(int[] rolls, int mean, int n) {
        int m = rolls.length;

        int sum = 0;

        for (int x : rolls) {
            sum += x;
        }

        int totalSum = mean * (m + n);
        int missingSum = totalSum - sum;

        // Impossible if the missing sum cannot be made
        // using n dice, each between 1 and 6.
        if (missingSum < n || missingSum > 6 * n) {
            return new int[0];
        }

        int[] ans = new int[n];

        // Give every die the minimum value 1.
        for (int i = 0; i < n; i++) {
            ans[i] = 1;
        }

        int extra = missingSum - n;

        for (int i = 0; i < n && extra > 0; i++) {
            int add = Math.min(5, extra);

            ans[i] += add;
            extra -= add;
        }

        return ans;
    }
}