
class Solution {
    private static final int MOD = 1_000_000_007;

    public int createSortedArray(int[] instructions) {
        int max = 0;

        for (int x : instructions) {
            max = Math.max(max, x);
        }

        FenwickTree bit = new FenwickTree(max);
        long totalCost = 0;

        for (int i = 0; i < instructions.length; i++) {
            int x = instructions[i];

            // Count existing elements strictly smaller than x
            int smaller = bit.query(x - 1);

            // Count existing elements less than or equal to x
            int lessOrEqual = bit.query(x);

            // Previously inserted elements strictly greater than x
            int greater = i - lessOrEqual;

            totalCost = (totalCost + Math.min(smaller, greater)) % MOD;

            // Insert x into the frequency tree
            bit.update(x);
        }

        return (int) totalCost;
    }

    private static class FenwickTree {
        private final int[] tree;
        private final int n;

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
