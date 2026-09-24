class Solution {
    public long interchangeableRectangles(int[][] rectangles) {
        Map<String, Long> freq = new HashMap<>();
        long ans = 0;

        for (int[] rect : rectangles) {
            int w = rect[0];
            int h = rect[1];

            int g = gcd(w, h);

            w /= g;
            h /= g;

            String ratio = w + "/" + h;

            long count = freq.getOrDefault(ratio, 0L);

            ans += count;
            freq.put(ratio, count + 1);
        }

        return ans;
    }

    private int gcd(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }

        return a;
    }
}