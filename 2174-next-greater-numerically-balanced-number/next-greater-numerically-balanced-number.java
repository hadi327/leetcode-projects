class Solution {
    public int nextBeautifulNumber(int n) {
        int num = n + 1;

        while (true) {
            if (isBalanced(num)) {
                return num;
            }
            num++;
        }
    }

    private boolean isBalanced(int num) {
        int[] count = new int[10];

        while (num > 0) {
            count[num % 10]++;
            num /= 10;
        }

        for (int digit = 0; digit <= 9; digit++) {
            if (count[digit] != 0 && count[digit] != digit) {
                return false;
            }
        }

        return true;
    }
}