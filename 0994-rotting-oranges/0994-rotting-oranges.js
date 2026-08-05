/**
 * @param {number[][]} grid
 * @return {number}
 */
var orangesRotting = function(grid) {
    const rows = grid.length;
    const cols = grid[0].length;

    const queue = [];
    let fresh = 0;

    // Initialize queue with all rotten oranges
    for (let r = 0; r < rows; r++) {
        for (let c = 0; c < cols; c++) {
            if (grid[r][c] === 2) {
                queue.push([r, c]);
            } else if (grid[r][c] === 1) {
                fresh++;
            }
        }
    }

    if (fresh === 0) return 0;

    const dirs = [
        [1, 0],
        [-1, 0],
        [0, 1],
        [0, -1]
    ];

    let minutes = 0;
    let front = 0;

    while (front < queue.length && fresh > 0) {
        let size = queue.length - front;

        while (size--) {
            const [r, c] = queue[front++];

            for (const [dr, dc] of dirs) {
                const nr = r + dr;
                const nc = c + dc;

                if (
                    nr >= 0 &&
                    nr < rows &&
                    nc >= 0 &&
                    nc < cols &&
                    grid[nr][nc] === 1
                ) {
                    grid[nr][nc] = 2;
                    fresh--;
                    queue.push([nr, nc]);
                }
            }
        }

        minutes++;
    }

    return fresh === 0 ? minutes : -1;
};