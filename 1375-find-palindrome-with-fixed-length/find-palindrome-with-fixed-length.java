class Solution {
    public long[] kthPalindrome(int[] queries, int intLength) {
        long[] answer = new long[queries.length];

        int halfLength = (intLength + 1) / 2;

        long start = 1;
        for (int i = 1; i < halfLength; i++) {
            start *= 10;
        }

        long maxStart = start * 10 - 1;

        for (int i = 0; i < queries.length; i++) {
            long firstHalf = start + queries[i] - 1;

            if (firstHalf > maxStart) {
                answer[i] = -1;
                continue;
            }

            answer[i] = makePalindrome(
                firstHalf,
                intLength % 2 == 1
            );
        }

        return answer;
    }

    private long makePalindrome(long firstHalf, boolean oddLength) {
        long result = firstHalf;
        long x = oddLength ? firstHalf / 10 : firstHalf;

        while (x > 0) {
            result = result * 10 + x % 10;
            x /= 10;
        }

        return result;
    }
}