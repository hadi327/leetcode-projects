class Solution {
    public int minimizeSet(int divisor1, int divisor2,
                           int uniqueCnt1, int uniqueCnt2) {

        long left = 1;
        long right = 2_000_000_000L;

        long lcm = lcm(divisor1, divisor2);

        while (left < right) {
            long mid = left + (right - left) / 2;

            // Numbers usable by array 1
            long available1 = mid - mid / divisor1;

            // Numbers usable by array 2
            long available2 = mid - mid / divisor2;

            // Numbers usable by neither array
            long common = mid - mid / divisor1 - mid / divisor2
                    + mid / lcm;

            // Total numbers that can be distributed between both arrays
            long total = mid - mid / lcm;

            if (available1 >= uniqueCnt1
                    && available2 >= uniqueCnt2
                    && total >= (long) uniqueCnt1 + uniqueCnt2
                    && common >= Math.max(
                        0L,
                        (long) uniqueCnt1 + uniqueCnt2 - total)) {

                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return (int) left;
    }

    private long gcd(long a, long b) {
        while (b != 0) {
            long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    private long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }
}