class Solution {
    public int maximumDetonation(int[][] bombs) {
        int n = bombs.length;

        boolean[][] graph = new boolean[n][n];

        // Build the directed graph
        for (int i = 0; i < n; i++) {
            long x1 = bombs[i][0];
            long y1 = bombs[i][1];
            long r = bombs[i][2];

            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                long x2 = bombs[j][0];
                long y2 = bombs[j][1];

                long dx = x1 - x2;
                long dy = y1 - y2;

                if (dx * dx + dy * dy <= r * r) {
                    graph[i][j] = true;
                }
            }
        }

        int answer = 0;

        // Try detonating each bomb first
        for (int start = 0; start < n; start++) {
            boolean[] visited = new boolean[n];
            int count = dfs(start, graph, visited);
            answer = Math.max(answer, count);
        }

        return answer;
    }

    private int dfs(int node, boolean[][] graph, boolean[] visited) {
        visited[node] = true;
        int count = 1;

        for (int next = 0; next < graph.length; next++) {
            if (graph[node][next] && !visited[next]) {
                count += dfs(next, graph, visited);
            }
        }

        return count;
    }
}