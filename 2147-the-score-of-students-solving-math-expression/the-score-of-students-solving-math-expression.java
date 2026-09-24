class Solution {
    public int scoreOfStudents(String s, int[] answers) {
        int n = s.length();

        // dp[i][j] = possible values of substring i...j
        Set<Integer>[][] dp = new HashSet[n][n];

        for (int i = 0; i < n; i += 2) {
            dp[i][i] = new HashSet<>();
            dp[i][i].add(s.charAt(i) - '0');
        }

        // Length in terms of numbers
        for (int len = 2; len <= (n + 1) / 2; len++) {
            for (int l = 0; l + 2 * (len - 1) < n; l += 2) {
                int r = l + 2 * (len - 1);

                dp[l][r] = new HashSet<>();

                for (int mid = l + 1; mid < r; mid += 2) {
                    Set<Integer> left = dp[l][mid - 1];
                    Set<Integer> right = dp[mid + 1][r];

                    for (int a : left) {
                        for (int b : right) {
                            int value;

                            if (s.charAt(mid) == '+')
                                value = a + b;
                            else
                                value = a * b;

                            // Values above 1000 cannot be valid answers
                            // according to the problem constraints.
                            if (value <= 1000)
                                dp[l][r].add(value);
                        }
                    }
                }
            }
        }

        // Correct answer using normal precedence.
        int correct = evaluate(s);

        int score = 0;

        for (int answer : answers) {
            if (answer == correct) {
                score += 5;
            } else if (dp[0][n - 1].contains(answer)) {
                score += 2;
            }
        }

        return score;
    }

    private int evaluate(String s) {
        int result = 0;
        int current = s.charAt(0) - '0';
        char operator = '+';

        for (int i = 1; i < s.length(); i += 2) {
            char op = s.charAt(i);
            int num = s.charAt(i + 1) - '0';

            if (op == '*') {
                current *= num;
            } else {
                result += current;
                current = num;
            }
        }

        result += current;

        return result;
    }
}