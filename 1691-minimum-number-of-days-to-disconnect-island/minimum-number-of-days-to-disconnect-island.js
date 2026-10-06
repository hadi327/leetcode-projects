var minDays = function(grid) {
    const m = grid.length;
    const n = grid[0].length;

    function countIslands() {
        let visited = Array.from(
            { length: m },
            () => Array(n).fill(false)
        );

        let islands = 0;
        const directions = [[1,0], [-1,0], [0,1], [0,-1]];

        function dfs(r, c) {
            if (
                r < 0 || r >= m ||
                c < 0 || c >= n ||
                grid[r][c] === 0 ||
                visited[r][c]
            ) {
                return;
            }

            visited[r][c] = true;

            for (let [dr, dc] of directions) {
                dfs(r + dr, c + dc);
            }
        }

        for (let r = 0; r < m; r++) {
            for (let c = 0; c < n; c++) {
                if (grid[r][c] === 1 && !visited[r][c]) {
                    islands++;
                    dfs(r, c);
                }
            }
        }

        return islands;
    }

    // Already disconnected
    if (countIslands() !== 1) {
        return 0;
    }

    // Try removing one land cell
    for (let r = 0; r < m; r++) {
        for (let c = 0; c < n; c++) {
            if (grid[r][c] === 1) {
                grid[r][c] = 0;

                if (countIslands() !== 1) {
                    grid[r][c] = 1;
                    return 1;
                }

                grid[r][c] = 1;
            }
        }
    }

    // If one cell isn't enough, two always are enough
    return 2;
};