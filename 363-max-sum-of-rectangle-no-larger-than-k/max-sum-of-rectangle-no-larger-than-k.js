var maxSumSubmatrix = function(matrix, k) {
    const m = matrix.length;
    const n = matrix[0].length;
    let answer = -Infinity;

    for (let left = 0; left < n; left++) {
        const rowSum = new Array(m).fill(0);

        for (let right = left; right < n; right++) {
            for (let i = 0; i < m; i++) {
                rowSum[i] += matrix[i][right];
            }

            for (let top = 0; top < m; top++) {
                let sum = 0;

                for (let bottom = top; bottom < m; bottom++) {
                    sum += rowSum[bottom];

                    if (sum <= k) {
                        answer = Math.max(answer, sum);
                    }
                }
            }
        }
    }

    return answer;
};