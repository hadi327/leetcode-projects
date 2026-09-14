class Solution {
public:
    vector<vector<int>> pacificAtlantic(
        vector<vector<int>>& heights
    ) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(
            m, vector<bool>(n, false)
        );

        vector<vector<bool>> atlantic(
            m, vector<bool>(n, false)
        );

        function<void(int, int, vector<vector<bool>>&)> dfs =
            [&](int r, int c, vector<vector<bool>>& visited) {
                if (visited[r][c]) {
                    return;
                }

                visited[r][c] = true;

                int dr[] = {-1, 1, 0, 0};
                int dc[] = {0, 0, -1, 1};

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n ||
                        visited[nr][nc]) {
                        continue;
                    }

                    if (heights[nr][nc] >= heights[r][c]) {
                        dfs(nr, nc, visited);
                    }
                }
            };

        for (int i = 0; i < m; i++) {
            dfs(i, 0, pacific);
            dfs(i, n - 1, atlantic);
        }

        for (int j = 0; j < n; j++) {
            dfs(0, j, pacific);
            dfs(m - 1, j, atlantic);
        }

        vector<vector<int>> result;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};