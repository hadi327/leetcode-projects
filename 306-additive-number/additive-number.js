var isAdditiveNumber = function(num) {
    const n = num.length;

    function dfs(index, a, b, count) {
        if (index === n) {
            return count >= 3;
        }

        let c = "";

        for (let i = index; i < n; i++) {
            c += num[i];

            // No leading zero
            if (c.length > 1 && c[0] === "0") {
                break;
            }

            const sum = BigInt(a) + BigInt(b);

            if (BigInt(c) < sum) continue;
            if (BigInt(c) > sum) break;

            if (dfs(i + 1, b, c, count + 1)) {
                return true;
            }
        }

        return false;
    }

    for (let i = 1; i < n; i++) {
        if (i > 1 && num[0] === "0") break;

        const a = num.slice(0, i);

        for (let j = i + 1; j < n; j++) {
            if (j - i > 1 && num[i] === "0") break;

            const b = num.slice(i, j);

            if (dfs(j, a, b, 2)) {
                return true;
            }
        }
    }

    return false;
};