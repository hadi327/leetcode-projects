import java.util.*;

class Solution {
    public long countPairs(int[] nums, int k) {
        Map<Long, Long> freq = new HashMap<>();
        long answer = 0;

        for (int num : nums) {
            long g = gcd(num, k);

            for (long prev : freq.keySet()) {
                if ((g * prev) % k == 0) {
                    answer += freq.get(prev);
                }
            }

            freq.put(g, freq.getOrDefault(g, 0L) + 1);
        }

        return answer;
    }

    private long gcd(long a, long b) {
        while (b != 0) {
            long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
}