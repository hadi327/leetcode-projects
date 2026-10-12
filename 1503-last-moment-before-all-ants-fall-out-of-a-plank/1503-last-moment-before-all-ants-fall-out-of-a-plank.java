
class Solution {
    public int getLastMoment(int n, int[] left, int[] right) {
        int last = 0;

        // Ants moving left fall off at their positions
        for (int pos : left) {
            last = Math.max(last, pos);
        }

        // Ants moving right fall off after n - pos units
        for (int pos : right) {
            last = Math.max(last, n - pos);
        }

        return last;
    }
}
