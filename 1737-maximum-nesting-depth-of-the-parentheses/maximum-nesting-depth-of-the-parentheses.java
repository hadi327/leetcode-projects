class Solution {
    public int maxDepth(String s) {
        int depth = 0;
        int answer = 0;

        for (char c : s.toCharArray()) {
            if (c == '(') {
                depth++;
                answer = Math.max(answer, depth);
            } else if (c == ')') {
                depth--;
            }
        }

        return answer;
    }
}