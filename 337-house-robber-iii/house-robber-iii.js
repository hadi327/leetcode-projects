var rob = function(root) {
    function dfs(node) {
        if (node === null) {
            return [0, 0];
        }

        const left = dfs(node.left);
        const right = dfs(node.right);

        // Rob current node
        const robCurrent =
            node.val + left[1] + right[1];

        // Don't rob current node
        const skipCurrent =
            Math.max(left[0], left[1]) +
            Math.max(right[0], right[1]);

        return [robCurrent, skipCurrent];
    }

    const [robRoot, skipRoot] = dfs(root);

    return Math.max(robRoot, skipRoot);
};