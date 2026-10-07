var removeInvalidParentheses = function(s) {
    const result = [];
    let found = false;

    function isValid(str) {
        let count = 0;

        for (const ch of str) {
            if (ch === "(") count++;
            else if (ch === ")") count--;

            if (count < 0) return false;
        }

        return count === 0;
    }

    function dfs(str, start, left, right) {
        if (found) return;

        if (left === 0 && right === 0) {
            if (isValid(str)) {
                result.push(str);
                found = true;
            }
            return;
        }

        for (let i = start; i < str.length; i++) {
            if (i > start && str[i] === str[i - 1]) continue;

            if (left > 0 && str[i] === "(") {
                dfs(
                    str.slice(0, i) + str.slice(i + 1),
                    i,
                    left - 1,
                    right
                );
            }

            if (right > 0 && str[i] === ")") {
                dfs(
                    str.slice(0, i) + str.slice(i + 1),
                    i,
                    left,
                    right - 1
                );
            }
        }
    }

    let left = 0;
    let right = 0;

    for (const ch of s) {
        if (ch === "(") {
            left++;
        } else if (ch === ")") {
            if (left > 0) left--;
            else right++;
        }
    }

    function backtrack(str, index, l, r) {
        if (l === 0 && r === 0) {
            if (isValid(str)) {
                result.push(str);
            }
            return;
        }

        for (let i = index; i < str.length; i++) {
            if (i > index && str[i] === str[i - 1]) continue;

            if (l > 0 && str[i] === "(") {
                backtrack(
                    str.slice(0, i) + str.slice(i + 1),
                    i,
                    l - 1,
                    r
                );
            }

            if (r > 0 && str[i] === ")") {
                backtrack(
                    str.slice(0, i) + str.slice(i + 1),
                    i,
                    l,
                    r - 1
                );
            }
        }
    }

    backtrack(s, 0, left, right);

    return [...new Set(result)];
};