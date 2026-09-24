class Solution {
    public long minimumPerimeter(long neededApples) {
        long left = 0;
        long right = 100000;

        while (left < right) {
            long mid = left + (right - left) / 2;

            long apples = 2L * mid * (mid + 1) * (2 * mid + 1);

            if (apples >= neededApples) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return 8L * left;
    }
}