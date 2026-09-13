var kthSmallest = function(matrix, k) {
    const n = matrix.length;

    let left = matrix[0][0];
    let right = matrix[n - 1][n - 1];

    while (left < right) {
        const mid = Math.floor((left + right) / 2);
        let count = 0;

        let row = n - 1;
        let col = 0;

        while (row >= 0 && col < n) {
            if (matrix[row][col] <= mid) {
                count += row + 1;
                col++;
            } else {
                row--;
            }
        }

        if (count < k) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
};