var minOperations = function(nums) {
    let n = nums.length;
    let ones = 0;

    // Count existing 1s
    for (let num of nums) {
        if (num === 1) {
            ones++;
        }
    }

    // If we already have 1s
    if (ones > 0) {
        return n - ones;
    }

    // Find shortest subarray with GCD = 1
    let minLength = Infinity;

    for (let i = 0; i < n; i++) {
        let gcd = 0;

        for (let j = i; j < n; j++) {
            gcd = findGCD(gcd, nums[j]);

            if (gcd === 1) {
                minLength = Math.min(minLength, j - i + 1);
                break;
            }
        }
    }

    // No subarray has GCD 1
    if (minLength === Infinity) {
        return -1;
    }

    return (minLength - 1) + (n - 1);
};

function findGCD(a, b) {
    while (b !== 0) {
        let temp = a % b;
        a = b;
        b = temp;
    }

    return a;
}