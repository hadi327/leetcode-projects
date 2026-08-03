/**
 * @param {number[][]} grid
 * @return {number}
 */
var equalPairs = function(grid) {
     const map = new Map();

    // Store each row
    for (const row of grid) {
        const key = row.join(",");
        map.set(key, (map.get(key) || 0) + 1);
    }

    let ans = 0;
    const n = grid.length;

    // Check each column
    for (let j = 0; j < n; j++) {
        const col = [];

        for (let i = 0; i < n; i++) {
            col.push(grid[i][j]);
        }

        const key = col.join(",");
        ans += map.get(key) || 0;
    }

    return ans;
};