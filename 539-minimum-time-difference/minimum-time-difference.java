class Solution {
    public int findMinDifference(List<String> timePoints) {
        boolean[] seen = new boolean[1440];

        for (String time : timePoints) {
            int hour = Integer.parseInt(time.substring(0, 2));
            int minute = Integer.parseInt(time.substring(3));

            int total = hour * 60 + minute;

            if (seen[total])
                return 0;

            seen[total] = true;
        }

        int first = -1;
        int previous = -1;
        int result = 1440;

        for (int i = 0; i < 1440; i++) {
            if (seen[i]) {
                if (first == -1)
                    first = i;

                if (previous != -1)
                    result = Math.min(result, i - previous);

                previous = i;
            }
        }

        result = Math.min(result, 1440 - previous + first);

        return result;
    }
}