import java.util.PriorityQueue;

class Solution {
    public long totalCost(int[] costs, int k, int candidates) {
        PriorityQueue<Integer> left = new PriorityQueue<>();
        PriorityQueue<Integer> right = new PriorityQueue<>();

        int i = 0;
        int j = costs.length - 1;

        // Fill left heap
        while (i <= j && left.size() < candidates) {
            left.offer(costs[i++]);
        }

        // Fill right heap
        while (i <= j && right.size() < candidates) {
            right.offer(costs[j--]);
        }

        long ans = 0;

        while (k-- > 0) {
            if (right.isEmpty() || (!left.isEmpty() && left.peek() <= right.peek())) {
                ans += left.poll();

                if (i <= j) {
                    left.offer(costs[i++]);
                }
            } else {
                ans += right.poll();

                if (i <= j) {
                    right.offer(costs[j--]);
                }
            }
        }

        return ans;
    }
}