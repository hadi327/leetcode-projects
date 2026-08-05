/**
 * @param {number} n
 * @param {number[][]} connections
 * @return {number}
 */
var minReorder = function(n, connections) {
    const graph = Array.from({ length: n }, () => []);

    for (const [u, v] of connections) {
        graph[u].push([v, 1]); // Original direction: u -> v
        graph[v].push([u, 0]); // Reverse direction
    }

    const visited = new Array(n).fill(false);
    let changes = 0;

    function dfs(city) {
        visited[city] = true;

        for (const [next, needsReverse] of graph[city]) {
            if (!visited[next]) {
                changes += needsReverse;
                dfs(next);
            }
        }
    }

    dfs(0);
    return changes;
};