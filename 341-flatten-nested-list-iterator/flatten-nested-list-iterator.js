var NestedIterator = function(nestedList) {
    this.stack = [];

    for (let i = nestedList.length - 1; i >= 0; i--) {
        this.stack.push(nestedList[i]);
    }
};

NestedIterator.prototype.next = function() {
    this.hasNext();
    return this.stack.pop().getInteger();
};

NestedIterator.prototype.hasNext = function() {
    while (this.stack.length > 0) {
        const top = this.stack[this.stack.length - 1];

        if (top.isInteger()) {
            return true;
        }

        this.stack.pop();

        const list = top.getList();

        for (let i = list.length - 1; i >= 0; i--) {
            this.stack.push(list[i]);
        }
    }

    return false;
};