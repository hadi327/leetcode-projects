var diameterOfBinaryTree = function(root) {
    let diameter = 0;

    function height(node) {
        if (node === null) {
            return 0;
        }

        const left = height(node.left);
        const right = height(node.right);

        // Diameter passing through this node
        diameter = Math.max(diameter, left + right);

        // Return height of this node
        return 1 + Math.max(left, right);
    }

    height(root);

    return diameter;
};