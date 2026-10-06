var validArrangement = function(pairs) {
    let graph = new Map();

    // Build graph
    for (let [u, v] of pairs) {
        if (!graph.has(u)) {
            graph.set(u, []);
        }

        graph.get(u).push(v);
    }

    // Find starting node
    let inDegree = new Map();
    let outDegree = new Map();

    for (let [u, v] of pairs) {
        outDegree.set(u, (outDegree.get(u) || 0) + 1);
        inDegree.set(v, (inDegree.get(v) || 0) + 1);
    }

    let start = pairs[0][0];

    for (let [node, degree] of outDegree) {
        if (degree > (inDegree.get(node) || 0)) {
            start = node;
            break;
        }
    }

    let path = [];

    function dfs(node) {
        let edges = graph.get(node);

        while (edges && edges.length > 0) {
            let next = edges.pop();
            dfs(next);
        }

        path.push(node);
    }

    dfs(start);

    path.reverse();

    let answer = [];

    for (let i = 0; i < path.length - 1; i++) {
        answer.push([path[i], path[i + 1]]);
    }

    return answer;
};