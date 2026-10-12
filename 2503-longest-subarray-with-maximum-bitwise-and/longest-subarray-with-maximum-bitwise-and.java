
class Solution {
    public int longestSubarray(int[] nums) {
        int max = 0;
        int current = 0;
        int longest = 0;

        for (int num : nums) {
            if (num > max) {
                max = num;
                current = 1;
                longest = 1;
            } else if (num == max) {
                current++;
                longest = Math.max(longest, current);
            } else {
                current = 0;
            }
        }

        return longest;
    }
}
