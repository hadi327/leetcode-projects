
import java.util.HashSet;
import java.util.Set;

class Solution {
    public int minImpossibleOR(int[] nums) {
        Set<Integer> set = new HashSet<>();

        for (int num : nums) {
            set.add(num);
        }

        int x = 1;

        while (set.contains(x)) {
            x <<= 1;
        }

        return x;
    }
}
