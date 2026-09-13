var largestOverlap = function(img1, img2) {
    const n = img1.length;
    let maxOverlap = 0;

    for (let r = -(n - 1); r <= n - 1; r++) {
        for (let c = -(n - 1); c <= n - 1; c++) {

            let overlap = 0;

            for (let i = 0; i < n; i++) {
                for (let j = 0; j < n; j++) {

                    const x = i + r;
                    const y = j + c;

                    if (
                        x >= 0 && x < n &&
                        y >= 0 && y < n &&
                        img1[i][j] === 1 &&
                        img2[x][y] === 1
                    ) {
                        overlap++;
                    }
                }
            }

            maxOverlap = Math.max(maxOverlap, overlap);
        }
    }

    return maxOverlap;
};