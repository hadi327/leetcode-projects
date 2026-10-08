/**
 * @param {number[]} nums
 * @return {number}
 */
var smallestUniqueSubarray = function(nums) {

    const n = nums.length;

    const BASE = 911382323n;
    const MOD = 1000000007n;

    const pow = new Array(n + 1).fill(0n);
    pow[0] = 1n;

    for (let i = 1; i <= n; i++) {
        pow[i] = (pow[i - 1] * BASE) % MOD;
    }

    const prefix = new Array(n + 1).fill(0n);

    for (let i = 0; i < n; i++) {
        prefix[i + 1] =
            (prefix[i] * BASE + BigInt(nums[i] + 1)) % MOD;
    }

    function getHash(l, r) {

        return (
            prefix[r + 1] -
            (prefix[l] * pow[r - l + 1]) % MOD +
            MOD
        ) % MOD;
    }

    function hasUnique(len) {

        const freq = new Map();

        for (let i = 0; i + len - 1 < n; i++) {

            const hash = getHash(i, i + len - 1).toString();

            freq.set(hash, (freq.get(hash) || 0) + 1);
        }

        for (let count of freq.values()) {
            if (count === 1) return true;
        }

        return false;
    }

    let low = 1;
    let high = n;
    let ans = n;

    while (low <= high) {

        let mid = Math.floor((low + high) / 2);

        if (hasUnique(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
};