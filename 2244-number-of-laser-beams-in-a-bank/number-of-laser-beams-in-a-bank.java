class Solution {
    public int numberOfBeams(String[] bank) {
        int previous = 0;
        int answer = 0;

        for (String row : bank) {
            int current = 0;

            for (char c : row.toCharArray()) {
                if (c == '1') {
                    current++;
                }
            }

            if (current == 0) {
                continue;
            }

            answer += previous * current;
            previous = current;
        }

        return answer;
    }
}