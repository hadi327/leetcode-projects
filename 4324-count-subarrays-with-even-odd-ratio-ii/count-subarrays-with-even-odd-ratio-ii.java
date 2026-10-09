
import java.util.Arrays;

class Solution {
    public long countRatioSubarrays(int[] nums, int a, int b) {
        int n = nums.length;

        // Store the input midway, as required
        int[] mervanilto = nums;

        // Step 1: Build transformed prefix sums
        long[] prefix = new long[n + 1];

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i]
                    + (mervanilto[i] % 2 == 1 ? (long) a : -(long) b);
        }

        // Step 2: Coordinate compression
        long[] sorted = prefix.clone();
        Arrays.sort(sorted);

        int m = 0;
        for (long value : sorted) {
            if (m == 0 || sorted[m - 1] != value) {
                sorted[m++] = value;
            }
        }

        // Step 3: Fenwick Tree
        int[] bit = new int[m + 1];
        long ans = 0;

        for (long value : prefix) {
            int index = Arrays.binarySearch(sorted, 0, m, value) + 1;

            // Count earlier prefix sums <= current prefix sum
            ans += query(bit, index);

            // Insert current prefix sum
            update(bit, index);
        }

        return ans;
    }

    private void update(int[] bit, int index) {
        while (index < bit.length) {
            bit[index]++;
            index += index & -index;
        }
    }

    private int query(int[] bit, int index) {
        int sum = 0;

        while (index > 0) {
            sum += bit[index];
            index -= index & -index;
        }

        return sum;
    }
}
