class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        if (m <= 2 || n <= 2) {
            return 0;
        }

        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        vector<vector<bool>> visited(
            m, vector<bool>(n, false)
        );

        for (int i = 0; i < m; i++) {
            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][n - 1], i, n - 1});

            visited[i][0] = true;
            visited[i][n - 1] = true;
        }

        for (int j = 1; j < n - 1; j++) {
            pq.push({heightMap[0][j], 0, j});
            pq.push({heightMap[m - 1][j], m - 1, j});

            visited[0][j] = true;
            visited[m - 1][j] = true;
        }

        int water = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [height, r, c] = pq.top();
            pq.pop();

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr < 0 || nr >= m ||
                    nc < 0 || nc >= n ||
                    visited[nr][nc]) {
                    continue;
                }

                visited[nr][nc] = true;

                if (heightMap[nr][nc] < height) {
                    water += height - heightMap[nr][nc];
                }

                pq.push({
                    max(height, heightMap[nr][nc]),
                    nr,
                    nc
                });
            }
        }

        return water;
    }
};