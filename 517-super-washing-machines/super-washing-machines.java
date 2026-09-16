class Solution {
    public int findMinMoves(int[] machines) {
        int total = 0;

        for (int machine : machines)
            total += machine;

        int n = machines.length;

        if (total % n != 0)
            return -1;

        int target = total / n;
        int balance = 0;
        int result = 0;

        for (int machine : machines) {
            int diff = machine - target;
            balance += diff;

            result = Math.max(result, Math.max(
                Math.abs(balance), diff
            ));
        }

        return result;
    }
}