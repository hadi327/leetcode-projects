var BSTIterator = function(root) {
    this.stack = [];

    this.pushLeft = function(node) {
        while (node) {
            this.stack.push(node);
            node = node.left;
        }
    };

    this.pushLeft(root);
};

BSTIterator.prototype.next = function() {
    const node = this.stack.pop();

    this.pushLeft(node.right);

    return node.val;
};

BSTIterator.prototype.hasNext = function() {
    return this.stack.length > 0;
};