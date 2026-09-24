import java.util.*;

class Solution {
    public long smallestNumber(long num) {
        if (num == 0) {
            return 0;
        }

        boolean negative = num < 0;
        char[] digits = Long.toString(Math.abs(num)).toCharArray();

        Arrays.sort(digits);

        if (negative) {
            // Largest digits first for the smallest negative number
            reverse(digits);
            return -Long.parseLong(new String(digits));
        }

        // Find the first non-zero digit
        int i = 0;
        while (digits[i] == '0') {
            i++;
        }

        // Put the first non-zero digit at the front
        char temp = digits[0];
        digits[0] = digits[i];
        digits[i] = temp;

        return Long.parseLong(new String(digits));
    }

    private void reverse(char[] arr) {
        int left = 0;
        int right = arr.length - 1;

        while (left < right) {
            char temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;

            left++;
            right--;
        }
    }
}