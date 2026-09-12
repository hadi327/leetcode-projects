class Result {
    constructor(score, indices) {
        this.score = score;
        this.indices = indices;
    }
}

var maximumWeight = function(intervals) {
    const n = intervals.length;

    // [left, right, weight, originalIndex]
    const arr = intervals.map((interval, i) => [
        interval[0],
        interval[1],
        interval[2],
        i
    ]);

    arr.sort((a, b) => {
        if (a[0] !== b[0]) return a[0] - b[0];
        if (a[1] !== b[1]) return a[1] - b[1];
        return a[3] - b[3];
    });

    // next[i] = first interval whose start > arr[i].right
    const next = new Array(n);

    for (let i = 0; i < n; i++) {
        next[i] = findNext(arr, arr[i][1]);
    }

    // dp[i][k]
    const dp = Array.from(
        { length: n + 1 },
        () => Array(5)
    );

    for (let k = 0; k <= 4; k++) {
        dp[n][k] = new Result(0, []);
    }

    for (let i = n - 1; i >= 0; i--) {
        dp[i][0] = new Result(0, []);

        for (let k = 1; k <= 4; k++) {

            // Skip
            const skip = dp[i + 1][k];

            // Take
            const afterTake = dp[next[i]][k - 1];

            const takeIndices = [
                arr[i][3],
                ...afterTake.indices
            ];

            takeIndices.sort((a, b) => a - b);

            const take = new Result(
                arr[i][2] + afterTake.score,
                takeIndices
            );

            dp[i][k] = better(skip, take);
        }
    }

    return dp[0][4].indices;
};

function findNext(arr, right) {
    let low = 0;
    let high = arr.length;

    while (low < high) {
        const mid = low + Math.floor((high - low) / 2);

        // Need next.left > current.right
        if (arr[mid][0] <= right) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return low;
}

function better(a, b) {
    if (a.score !== b.score) {
        return a.score > b.score ? a : b;
    }

    return isLexicographicallySmaller(
        a.indices,
        b.indices
    ) ? a : b;
}

function isLexicographicallySmaller(a, b) {
    const len = Math.min(a.length, b.length);

    for (let i = 0; i < len; i++) {
        if (a[i] !== b[i]) {
            return a[i] < b[i];
        }
    }

    return a.length < b.length;
}