var makeSubKSumEqual = function(arr, k) {
    let n = arr.length;
    let visited = new Array(n).fill(false);
    let operations = 0;

    for (let i = 0; i < n; i++) {
        if (visited[i]) continue;

        let group = [];
        let j = i;

        while (!visited[j]) {
            visited[j] = true;
            group.push(arr[j]);
            j = (j + k) % n;
        }

        group.sort((a, b) => a - b);

        let median = group[Math.floor(group.length / 2)];

        for (let num of group) {
            operations += Math.abs(num - median);
        }
    }

    return operations;
};