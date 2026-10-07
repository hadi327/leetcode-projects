var kthLargestValue = function(matrix, k) {
    const m = matrix.length;
    const n = matrix[0].length;

    const values = [];

    // prefix[i][j] = XOR of rectangle (0,0) -> (i-1,j-1)
    const prefix = Array.from(
        { length: m + 1 },
        () => Array(n + 1).fill(0)
    );

    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {

            prefix[i][j] =
                prefix[i - 1][j] ^
                prefix[i][j - 1] ^
                prefix[i - 1][j - 1] ^
                matrix[i - 1][j - 1];

            values.push(prefix[i][j]);
        }
    }

    // Sort largest -> smallest
    values.sort((a, b) => b - a);

    return values[k - 1];
};