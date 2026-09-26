import java.util.*;

class Solution {
    public int countLatticePoints(int[][] circles) {
        Set<String> points = new HashSet<>();

        for (int[] circle : circles) {
            int xc = circle[0];
            int yc = circle[1];
            int r = circle[2];

            for (int x = xc - r; x <= xc + r; x++) {
                for (int y = yc - r; y <= yc + r; y++) {

                    int dx = x - xc;
                    int dy = y - yc;

                    if (dx * dx + dy * dy <= r * r) {
                        points.add(x + "," + y);
                    }
                }
            }
        }

        return points.size();
    }
}