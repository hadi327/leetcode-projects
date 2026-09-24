class Solution {
    public boolean sumGame(String num) {
        int n = num.length();

        int leftSum = 0, rightSum = 0;
        int leftQ = 0, rightQ = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num.charAt(i) == '?')
                leftQ++;
            else
                leftSum += num.charAt(i) - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num.charAt(i) == '?')
                rightQ++;
            else
                rightSum += num.charAt(i) - '0';
        }

        int diff = leftSum - rightSum;
        int qDiff = leftQ - rightQ;

        // If the number of ? is odd, Alice can force a win.
        if ((qDiff & 1) != 0)
            return true;

        // Alice wins if the existing difference cannot be
        // compensated by the ? digits.
        return diff * 2 != -9 * qDiff;
    }
}