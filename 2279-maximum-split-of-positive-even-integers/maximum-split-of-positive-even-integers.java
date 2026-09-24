import java.util.*;

class Solution {
    public List<Long> maximumEvenSplit(long finalSum) {
        List<Long> result = new ArrayList<>();

        if (finalSum % 2 != 0) {
            return result;
        }

        long current = 2;
        long sum = 0;

        while (sum + current <= finalSum) {
            result.add(current);
            sum += current;
            current += 2;
        }

        // Add the remaining amount to the largest number
        if (sum < finalSum) {
            long remaining = finalSum - sum;
            int last = result.size() - 1;
            result.set(last, result.get(last) + remaining);
        }

        return result;
    }
}