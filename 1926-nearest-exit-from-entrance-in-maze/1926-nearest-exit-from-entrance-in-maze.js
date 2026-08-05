/**
 * @param {character[][]} maze
 * @param {number[]} entrance
 * @return {number}
 */
var nearestExit = function(maze, entrance) {
    const m = maze.length;
    const n = maze[0].length;

    const dirs = [
        [1, 0],
        [-1, 0],
        [0, 1],
        [0, -1]
    ];

    const queue = [[entrance[0], entrance[1], 0]];
    maze[entrance[0]][entrance[1]] = '+';

    while (queue.length) {
        const [r, c, steps] = queue.shift();

        if (
            (r === 0 || r === m - 1 || c === 0 || c === n - 1) &&
            !(r === entrance[0] && c === entrance[1])
        ) {
            return steps;
        }

        for (const [dr, dc] of dirs) {
            const nr = r + dr;
            const nc = c + dc;

            if (
                nr >= 0 &&
                nr < m &&
                nc >= 0 &&
                nc < n &&
                maze[nr][nc] === '.'
            ) {
                maze[nr][nc] = '+';
                queue.push([nr, nc, steps + 1]);
            }
        }
    }

    return -1;
};