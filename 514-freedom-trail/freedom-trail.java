class Solution {
    public int findRotateSteps(String ring, String key) {
        int n = ring.length();

        List<Integer>[] positions = new ArrayList[26];

        for (int i = 0; i < 26; i++)
            positions[i] = new ArrayList<>();

        for (int i = 0; i < n; i++)
            positions[ring.charAt(i) - 'a'].add(i);

        int[][] memo = new int[key.length()][n];

        for (int[] row : memo)
            Arrays.fill(row, -1);

        return dfs(ring, key, 0, 0, positions, memo);
    }

    private int dfs(String ring, String key,
                    int index, int current,
                    List<Integer>[] positions,
                    int[][] memo) {

        if (index == key.length())
            return 0;

        if (memo[index][current] != -1)
            return memo[index][current];

        int n = ring.length();
        int result = Integer.MAX_VALUE;

        for (int next : positions[key.charAt(index) - 'a']) {
            int distance = Math.abs(next - current);
            int rotation = Math.min(distance, n - distance);

            result = Math.min(
                result,
                rotation + 1 +
                dfs(ring, key, index + 1,
                    next, positions, memo)
            );
        }

        return memo[index][current] = result;
    }
}