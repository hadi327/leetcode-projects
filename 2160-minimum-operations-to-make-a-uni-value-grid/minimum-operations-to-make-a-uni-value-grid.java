import java.util.*;

class Solution {
    public int minOperations(int[][] grid, int x) {
        int m = grid.length;
        int n = grid[0].length;

        int[] arr = new int[m * n];
        int index = 0;

        for (int[] row : grid) {
            for (int value : row) {
                arr[index++] = value;
            }
        }

        // Check if transformation is possible
        for (int value : arr) {
            if ((value - arr[0]) % x != 0) {
                return -1;
            }
        }

        // Median minimizes sum of absolute differences
        Arrays.sort(arr);
        int median = arr[arr.length / 2];

        int operations = 0;

        for (int value : arr) {
            operations += Math.abs(value - median) / x;
        }

        return operations;
    }
}