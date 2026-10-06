var criticalConnections = function(n, connections) {
    let graph = Array.from({ length: n }, () => []);

    for (let [u, v] of connections) {
        graph[u].push(v);
        graph[v].push(u);
    }

    let disc = new Array(n).fill(-1);
    let low = new Array(n).fill(-1);
    let time = 0;
    let result = [];

    function dfs(u, parent) {
        disc[u] = low[u] = time++;

        for (let v of graph[u]) {
            // Don't immediately go back through the same edge
            if (v === parent) continue;

            // v hasn't been visited
            if (disc[v] === -1) {
                dfs(v, u);

                low[u] = Math.min(low[u], low[v]);

                // No back edge from v or its subtree
                if (low[v] > disc[u]) {
                    result.push([u, v]);
                }
            } else {
                // Back edge
                low[u] = Math.min(low[u], disc[v]);
            }
        }
    }

    dfs(0, -1);

    return result;
};