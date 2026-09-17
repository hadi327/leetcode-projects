class Solution {
    public boolean validSquare(int[] p1, int[] p2,
                               int[] p3, int[] p4) {

        long[] d = {
            distance(p1, p2),
            distance(p1, p3),
            distance(p1, p4),
            distance(p2, p3),
            distance(p2, p4),
            distance(p3, p4)
        };

        Arrays.sort(d);

        return d[0] > 0 &&
               d[0] == d[1] &&
               d[1] == d[2] &&
               d[2] == d[3] &&
               d[4] == d[5] &&
               d[4] == 2 * d[0];
    }

    private long distance(int[] a, int[] b) {
        long dx = a[0] - b[0];
        long dy = a[1] - b[1];

        return dx * dx + dy * dy;
    }
}