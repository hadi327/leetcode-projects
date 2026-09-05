var buildTree = function(preorder, inorder) {
    const position = new Map();

    // Store positions of values in inorder
    for (let i = 0; i < inorder.length; i++) {
        position.set(inorder[i], i);
    }

    let preIndex = 0;

    function build(left, right) {
        if (left > right) {
            return null;
        }

        // First element of preorder is the root
        const value = preorder[preIndex++];
        const root = new TreeNode(value);

        const mid = position.get(value);

        // Build left subtree
        root.left = build(left, mid - 1);

        // Build right subtree
        root.right = build(mid + 1, right);

        return root;
    }

    return build(0, inorder.length - 1);
};