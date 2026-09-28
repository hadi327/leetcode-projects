class Solution {
    public boolean sumOfNumberAndReverse(int num) {
        for (int x = 0; x <= num; x++) {
            if (x + reverse(x) == num) {
                return true;
            }
        }

        return false;
    }

    private int reverse(int x) {
        int reversed = 0;

        while (x > 0) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }

        return reversed;
    }
}