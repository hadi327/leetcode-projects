var minimumDifference = function(nums) {
    const n = nums.length;
    const half = n / 2;

    const left = nums.slice(0, half);
    const right = nums.slice(half);

    // Generate [sum, count] for every subset
    function getSums(arr) {
        const result = Array.from(
            { length: arr.length + 1 },
            () => []
        );

        function dfs(index, sum, count) {
            if (index === arr.length) {
                result[count].push(sum);
                return;
            }

            // Don't take arr[index]
            dfs(index + 1, sum, count);

            // Take arr[index]
            dfs(index + 1, sum + arr[index], count + 1);
        }

        dfs(0, 0, 0);
        return result;
    }

    const leftSums = getSums(left);
    const rightSums = getSums(right);

    for (const arr of rightSums) {
        arr.sort((a, b) => a - b);
    }

    const total = nums.reduce((sum, x) => sum + x, 0);
    let answer = Infinity;

    /*
        If we choose k elements from left,
        we need (half - k) elements from right.
    */
    for (let k = 0; k <= half; k++) {
        const A = leftSums[k];
        const B = rightSums[half - k];

        for (const x of A) {
            // We want:
            // selectedSum ≈ total / 2
            const target = total / 2 - x;

            // Binary search in B
            let lo = 0;
            let hi = B.length - 1;

            while (lo <= hi) {
                const mid = Math.floor((lo + hi) / 2);

                if (B[mid] < target) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }

            if (lo < B.length) {
                const selectedSum = x + B[lo];
                answer = Math.min(
                    answer,
                    Math.abs(total - 2 * selectedSum)
                );
            }

            if (hi >= 0) {
                const selectedSum = x + B[hi];
                answer = Math.min(
                    answer,
                    Math.abs(total - 2 * selectedSum)
                );
            }
        }
    }

    return answer;
};