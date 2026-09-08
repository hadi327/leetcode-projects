var PeekingIterator = function(iterator) {
    this.iterator = iterator;
    this.nextValue = iterator.hasNext()
        ? iterator.next()
        : null;
};

PeekingIterator.prototype.peek = function() {
    return this.nextValue;
};

PeekingIterator.prototype.next = function() {
    let value = this.nextValue;

    this.nextValue = this.iterator.hasNext()
        ? this.iterator.next()
        : null;

    return value;
};

PeekingIterator.prototype.hasNext = function() {
    return this.nextValue !== null;
};