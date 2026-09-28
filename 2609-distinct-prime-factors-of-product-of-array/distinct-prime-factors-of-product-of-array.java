import java.util.*;

class Solution {
    public int distinctPrimeFactors(int[] nums) {
        Set<Integer> factors = new HashSet<>();

        for (int num : nums) {
            for (int p = 2; p * p <= num; p++) {
                if (num % p == 0) {
                    factors.add(p);

                    while (num % p == 0) {
                        num /= p;
                    }
                }
            }

            if (num > 1) {
                factors.add(num);
            }
        }

        return factors.size();
    }
}