/**
 * @param {string[][]} equations
 * @param {number[]} values
 * @param {string[][]} queries
 * @return {number[]}
 */
var calcEquation = function(equations, values, queries) {
    const graph = new Map();

    // Build graph
    for (let i = 0; i < equations.length; i++) {
        const [a, b] = equations[i];
        const value = values[i];

        if (!graph.has(a)) graph.set(a, []);
        if (!graph.has(b)) graph.set(b, []);

        graph.get(a).push([b, value]);
        graph.get(b).push([a, 1 / value]);
    }

    function dfs(curr, target, product, visited) {
        if (curr === target) return product;

        visited.add(curr);

        for (const [next, weight] of graph.get(curr)) {
            if (!visited.has(next)) {
                const result = dfs(next, target, product * weight, visited);
                if (result !== -1) return result;
            }
        }

        return -1;
    }

    const ans = [];

    for (const [start, end] of queries) {
        if (!graph.has(start) || !graph.has(end)) {
            ans.push(-1.0);
        } else {
            ans.push(dfs(start, end, 1, new Set()));
        }
    }

    return ans;
};