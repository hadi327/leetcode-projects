import java.util.*;

class Solution {
    public int componentValue(int[] nums, int[][] edges) {
        int n = nums.length;

        List<Integer>[] graph = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int[] edge : edges) {
            graph[edge[0]].add(edge[1]);
            graph[edge[1]].add(edge[0]);
        }

        int total = 0;
        for (int x : nums) {
            total += x;
        }

        // Try the maximum possible number of components first.
        for (int components = n; components >= 1; components--) {
            if (total % components != 0) {
                continue;
            }

            int target = total / components;

            if (canSplit(0, -1, graph, nums, target) == 0) {
                return components - 1;
            }
        }

        return 0;
    }

    private int canSplit(int node, int parent,
                         List<Integer>[] graph,
                         int[] nums, int target) {

        int sum = nums[node];

        for (int next : graph[node]) {
            if (next == parent) {
                continue;
            }

            int childSum = canSplit(next, node, graph, nums, target);

            if (childSum == -1) {
                return -1;
            }

            sum += childSum;

            if (sum > target) {
                return -1;
            }
        }

        if (sum == target) {
            return 0;
        }

        return sum;
    }
}