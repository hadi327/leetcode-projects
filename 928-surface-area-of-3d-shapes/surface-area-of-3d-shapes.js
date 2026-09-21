var surfaceArea = function(grid) {
    let area = 0;
    let rows = grid.length;
    let cols = grid[0].length;

    for (let r = 0; r < rows; r++) {
        for (let c = 0; c < cols; c++) {
            let h = grid[r][c];

            if (h === 0) continue;

            // All 6 faces
            area += 6 * h;

            // Internal faces between cubes in the same column
            area -= 2 * Math.max(0, h - 1);

            // Shared faces with top neighbor
            if (r > 0) {
                area -= 2 * Math.min(h, grid[r - 1][c]);
            }

            // Shared faces with left neighbor
            if (c > 0) {
                area -= 2 * Math.min(h, grid[r][c - 1]);
            }
        }
    }

    return area;
};