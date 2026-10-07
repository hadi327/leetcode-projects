var minAbsDifference = function(nums, goal) {
    const n = nums.length;
    const mid = Math.floor(n / 2);

    const left = nums.slice(0, mid);
    const right = nums.slice(mid);

    function getSums(arr) {
        const sums = [0];

        for (const x of arr) {
            const size = sums.length;

            for (let i = 0; i < size; i++) {
                sums.push(sums[i] + x);
            }
        }

        return sums;
    }

    const a = getSums(left);
    const b = getSums(right);

    b.sort((x, y) => x - y);

    let ans = Infinity;

    for (const x of a) {
        const target = goal - x;

        // Binary search for target in b
        let lo = 0;
        let hi = b.length - 1;

        while (lo <= hi) {
            const mid = Math.floor((lo + hi) / 2);

            if (b[mid] === target) {
                return 0;
            } else if (b[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        // hi = largest value <= target
        if (hi >= 0) {
            ans = Math.min(ans, Math.abs(x + b[hi] - goal));
        }

        // lo = smallest value >= target
        if (lo < b.length) {
            ans = Math.min(ans, Math.abs(x + b[lo] - goal));
        }
    }

    return ans;
};