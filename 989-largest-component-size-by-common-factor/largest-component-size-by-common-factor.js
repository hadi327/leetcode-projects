var largestComponentSize = function(nums) {
    const n = nums.length;

    const parent = Array.from({ length: n }, (_, i) => i);
    const size = new Array(n).fill(1);

    function find(x) {
        if (parent[x] !== x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    function union(a, b) {
        let ra = find(a);
        let rb = find(b);

        if (ra === rb) return;

        if (size[ra] < size[rb]) {
            [ra, rb] = [rb, ra];
        }

        parent[rb] = ra;
        size[ra] += size[rb];
    }

    // factor -> index of first number containing this factor
    const factorOwner = new Map();

    function getPrimeFactors(num) {
        const factors = [];

        for (let p = 2; p * p <= num; p++) {
            if (num % p === 0) {
                factors.push(p);

                while (num % p === 0) {
                    num /= p;
                }
            }
        }

        if (num > 1) {
            factors.push(num);
        }

        return factors;
    }

    for (let i = 0; i < n; i++) {
        const factors = getPrimeFactors(nums[i]);

        for (const factor of factors) {
            if (factorOwner.has(factor)) {
                union(i, factorOwner.get(factor));
            } else {
                factorOwner.set(factor, i);
            }
        }
    }

    let answer = 1;

    for (let i = 0; i < n; i++) {
        answer = Math.max(answer, size[find(i)]);
    }

    return answer;
};