var crackSafe = function(n, k) {
    let result = [];
    let visited = new Set();

    // Start with n-1 zeros
    let start = "0".repeat(n - 1);

    function dfs(node) {
        for (let digit = 0; digit < k; digit++) {
            let edge = node + digit;

            if (!visited.has(edge)) {
                visited.add(edge);

                // Move to the last n-1 digits
                dfs(edge.slice(1));

                result.push(digit);
            }
        }
    }

    dfs(start);

    return start + result.reverse().join("");
};