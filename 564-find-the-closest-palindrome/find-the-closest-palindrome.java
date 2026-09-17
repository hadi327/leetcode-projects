class Solution {
    public String nearestPalindromic(String n) {
        long num = Long.parseLong(n);
        int len = n.length();

        Set<Long> candidates = new HashSet<>();

        candidates.add((long) Math.pow(10, len - 1) - 1);
        candidates.add((long) Math.pow(10, len) + 1);

        long prefix = Long.parseLong(
            n.substring(0, (len + 1) / 2)
        );

        for (long p = prefix - 1; p <= prefix + 1; p++) {
            String left = String.valueOf(p);

            String palindrome;

            if (len % 2 == 0) {
                palindrome = left +
                    new StringBuilder(left)
                        .reverse().toString();
            } else {
                palindrome = left +
                    new StringBuilder(
                        left.substring(0, left.length() - 1)
                    ).reverse().toString();
            }

            candidates.add(Long.parseLong(palindrome));
        }

        long answer = -1;

        for (long candidate : candidates) {
            if (candidate == num)
                continue;

            if (answer == -1 ||
                Math.abs(candidate - num) <
                Math.abs(answer - num) ||
                (Math.abs(candidate - num) ==
                 Math.abs(answer - num) &&
                 candidate < answer)) {

                answer = candidate;
            }
        }

        return String.valueOf(answer);
    }
}