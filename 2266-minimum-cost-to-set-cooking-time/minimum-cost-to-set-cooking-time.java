class Solution {
    public int minCostSetTime(
            int startAt,
            int moveCost,
            int pushCost,
            int targetSeconds) {

        int answer = Integer.MAX_VALUE;

        // Try every possible minute value.
        for (int minutes = 0; minutes <= 99; minutes++) {
            int seconds = targetSeconds - minutes * 60;

            if (seconds < 0 || seconds > 99) {
                continue;
            }

            String time = String.format("%02d%02d", minutes, seconds);

            answer = Math.min(
                answer,
                calculateCost(
                    time,
                    startAt,
                    moveCost,
                    pushCost
                )
            );
        }

        return answer;
    }

    private int calculateCost(
            String time,
            int startAt,
            int moveCost,
            int pushCost) {

        // Remove leading zeroes.
        int first = 0;

        while (first < time.length() - 1 &&
               time.charAt(first) == '0') {
            first++;
        }

        int cost = 0;
        int current = startAt;

        for (int i = first; i < time.length(); i++) {
            int digit = time.charAt(i) - '0';

            if (digit != current) {
                cost += moveCost;
                current = digit;
            }

            cost += pushCost;
        }

        return cost;
    }
}