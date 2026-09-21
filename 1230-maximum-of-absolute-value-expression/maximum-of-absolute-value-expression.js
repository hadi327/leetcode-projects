var maxAbsValExpr = function(arr1, arr2) {
    let answer = 0;

    const signs = [
        [1, 1, 1],
        [1, 1, -1],
        [1, -1, 1],
        [1, -1, -1]
    ];

    for (const [s1, s2, s3] of signs) {
        let minValue = Infinity;
        let maxValue = -Infinity;

        for (let i = 0; i < arr1.length; i++) {
            const value =
                s1 * arr1[i] +
                s2 * arr2[i] +
                s3 * i;

            minValue = Math.min(minValue, value);
            maxValue = Math.max(maxValue, value);
        }

        answer = Math.max(answer, maxValue - minValue);
    }

    return answer;
};