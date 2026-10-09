
class Solution {
    public long goodTriplets(int[] nums1, int[] nums2) {
        int n = nums1.length;

        // Map each value to its index in nums2
        int[] pos = new int[n];

        for (int i = 0; i < n; i++) {
            pos[nums2[i]] = i;
        }

        // Transform nums1 into positions in nums2
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = pos[nums1[i]];
        }

        int[] leftLess = new int[n];
        FenwickTree bit = new FenwickTree(n);

        // Count smaller elements to the left
        for (int i = 0; i < n; i++) {
            leftLess[i] = bit.query(arr[i]);
            bit.update(arr[i] + 1);
        }

        bit = new FenwickTree(n);
        long answer = 0;

        // Count greater elements to the right
        for (int i = n - 1; i >= 0; i--) {
            int rightCount = n - 1 - i;
            int rightLessOrEqual = bit.query(arr[i] + 1);
            int rightGreater = rightCount - rightLessOrEqual;

            answer += (long) leftLess[i] * rightGreater;

            bit.update(arr[i] + 1);
        }

        return answer;
    }

    private static class FenwickTree {
        int[] tree;
        int n;

        FenwickTree(int n) {
            this.n = n;
            tree = new int[n + 1];
        }

        void update(int index) {
            while (index <= n) {
                tree[index]++;
                index += index & -index;
            }
        }

        int query(int index) {
            int sum = 0;

            while (index > 0) {
                sum += tree[index];
                index -= index & -index;
            }

            return sum;
        }
    }
}
