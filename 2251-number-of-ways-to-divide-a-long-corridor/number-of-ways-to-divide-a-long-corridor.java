class Solution {
    public int numberOfWays(String corridor) {
        final long MOD = 1_000_000_007L;

        int seats = 0;
        long answer = 1;

        int plants = 0;
        boolean hasCompletedPair = false;

        for (char c : corridor.toCharArray()) {
            if (c == 'S') {
                seats++;

                // This is the first seat of a new pair
                if (seats % 2 == 1) {
                    if (seats > 1) {
                        answer = answer * (plants + 1) % MOD;
                    }
                    plants = 0;
                }
            } else {
                // Count plants after completing a pair
                if (seats >= 2 && seats % 2 == 0) {
                    plants++;
                }
            }
        }

        // We need a positive even number of seats
        if (seats == 0 || seats % 2 != 0) {
            return 0;
        }

        return (int) answer;
    }
}