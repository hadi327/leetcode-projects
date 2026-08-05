/**
 * @param {number[][]} isConnected
 * @return {number}
 */
var findCircleNum = function(isConnected) {
    const n = isConnected.length;
    const visited = new Array(n).fill(false);
    let provinces = 0;

    function dfs(city) {
        visited[city] = true;

        for (let next = 0; next < n; next++) {
            if (isConnected[city][next] === 1 && !visited[next]) {
                dfs(next);
            }
        }
    }

    for (let city = 0; city < n; city++) {
        if (!visited[city]) {
            provinces++;
            dfs(city);
        }
    }

    return provinces;
};