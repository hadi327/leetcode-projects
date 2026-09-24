import java.util.*;

class Solution {
    public List<Integer> replaceNonCoprimes(int[] nums) {
        List<Integer> stack = new ArrayList<>();

        for (int num : nums) {
            long current = num;

            while (!stack.isEmpty()) {
                long last = stack.get(stack.size() - 1);
                long g = gcd(last, current);

                if (g == 1) {
                    break;
                }

                // LCM = (a / gcd(a,b)) * b
                current = (last / g) * current;
                stack.remove(stack.size() - 1);
            }

            stack.add((int) current);
        }

        return stack;
    }

    private long gcd(long a, long b) {
        while (b != 0) {
            long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
}