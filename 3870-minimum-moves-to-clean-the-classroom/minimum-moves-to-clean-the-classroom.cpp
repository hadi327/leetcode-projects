class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        // Required by the problem
        auto lumetarkon = classroom;

        int sr = 0, sc = 0;
        int litterCount = 0;

        // Store litter bit number directly for each cell
        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                else if (classroom[i][j] == 'L') {
                    id[i][j] = litterCount++;
                }
            }
        }

        if (litterCount == 0)
            return 0;

        int fullMask = (1 << litterCount) - 1;

        // vector<bool> uses bit compression
        vector<vector<vector<vector<bool>>>> vis(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << litterCount, false)
                )
            )
        );

        queue<tuple<int,int,int,int>> q;

        // r, c, remaining energy, collected mask
        q.push({sr, sc, energy, 0});
        vis[sr][sc][energy][0] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int moves = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto [r, c, e, mask] = q.front();
                q.pop();

                if (mask == fullMask)
                    return moves;

                if (e == 0)
                    continue;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n ||
                        classroom[nr][nc] == 'X')
                        continue;

                    int ne = e - 1;
                    int newMask = mask;

                    // Collect litter
                    if (classroom[nr][nc] == 'L') {
                        newMask |= (1 << id[nr][nc]);
                    }

                    // Recharge
                    if (classroom[nr][nc] == 'R') {
                        ne = energy;
                    }

                    if (!vis[nr][nc][ne][newMask]) {
                        vis[nr][nc][ne][newMask] = true;
                        q.push({nr, nc, ne, newMask});
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};