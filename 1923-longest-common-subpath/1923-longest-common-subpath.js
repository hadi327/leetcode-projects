/**
 * @param {number} n
 * @param {number[][]} paths
 * @return {number}
 */
var longestCommonSubpath = function(n, paths) {
    const MOD1 = 1000000007;
    const MOD2 = 1000000009;
    const BASE = 100003;

    const m = paths.length;

    // Shortest path gives an upper bound
    let maxLen = Infinity;

    for (const path of paths) {
        maxLen = Math.min(maxLen, path.length);
    }

    // Precompute powers
    const power1 = new Array(maxLen + 1).fill(1);
    const power2 = new Array(maxLen + 1).fill(1);

    for (let i = 1; i <= maxLen; i++) {
        power1[i] = (power1[i - 1] * BASE) % MOD1;
        power2[i] = (power2[i - 1] * BASE) % MOD2;
    }

    // Check whether every path contains
    // a common subpath of length len
    function check(len) {
        if (len === 0) return true;

        let common = null;

        for (let p = 0; p < m; p++) {
            const path = paths[p];

            const current = new Set();

            let h1 = 0;
            let h2 = 0;

            // First window
            for (let i = 0; i < len; i++) {
                h1 = (h1 * BASE + path[i] + 1) % MOD1;
                h2 = (h2 * BASE + path[i] + 1) % MOD2;
            }

            current.add(h1 * MOD2 + h2);

            // Remaining windows
            for (let i = len; i < path.length; i++) {
                const outgoing = path[i - len] + 1;
                const incoming = path[i] + 1;

                h1 = (
                    (h1 * BASE
                    - outgoing * power1[len]
                    + incoming)
                    % MOD1 + MOD1
                ) % MOD1;

                h2 = (
                    (h2 * BASE
                    - outgoing * power2[len]
                    + incoming)
                    % MOD2 + MOD2
                ) % MOD2;

                current.add(h1 * MOD2 + h2);
            }

            // First path initializes the common set
            if (common === null) {
                common = current;
            } else {
                // Keep only hashes appearing in both
                const next = new Set();

                for (const hash of common) {
                    if (current.has(hash)) {
                        next.add(hash);
                    }
                }

                common = next;

                if (common.size === 0) {
                    return false;
                }
            }
        }

        return common.size > 0;
    }

    // Binary search answer
    let left = 0;
    let right = maxLen;

    while (left <= right) {
        const mid = Math.floor((left + right) / 2);

        if (check(mid)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return right;
};