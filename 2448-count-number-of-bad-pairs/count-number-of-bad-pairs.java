import java.util.*;

class Solution {
    public long countBadPairs(int[] nums) {
        Map<Integer, Long> freq = new HashMap<>();

        long goodPairs = 0;
        int n = nums.length;

        for (int i = 0; i < n; i++) {
            int key = nums[i] - i;

            long count = freq.getOrDefault(key, 0L);

            goodPairs += count;
            freq.put(key, count + 1);
        }

        long totalPairs = (long) n * (n - 1) / 2;

        return totalPairs - goodPairs;
    }
}