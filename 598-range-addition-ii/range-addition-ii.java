class Solution {
    public int maxCount(int m, int n, int[][] ops) {
        int minRows = m;
        int minCols = n;

        for (int[] op : ops) {
            minRows = Math.min(minRows, op[0]);
            minCols = Math.min(minCols, op[1]);
        }

        return minRows * minCols;
    }
}