
import java.util.*;

class Solution {
    public int minimumPairRemoval(int[] nums) {
        List<Integer> arr = new ArrayList<>();

        for (int num : nums) {
            arr.add(num);
        }

        int operations = 0;

        while (!isSorted(arr)) {
            int minSum = Integer.MAX_VALUE;
            int index = 0;

            // Find the leftmost adjacent pair
            // having the minimum sum
            for (int i = 0; i < arr.size() - 1; i++) {
                int sum = arr.get(i) + arr.get(i + 1);

                if (sum < minSum) {
                    minSum = sum;
                    index = i;
                }
            }

            // Merge the pair
            arr.set(index, minSum);
            arr.remove(index + 1);

            operations++;
        }

        return operations;
    }

    private boolean isSorted(List<Integer> arr) {
        for (int i = 1; i < arr.size(); i++) {
            if (arr.get(i) < arr.get(i - 1)) {
                return false;
            }
        }

        return true;
    }
}
