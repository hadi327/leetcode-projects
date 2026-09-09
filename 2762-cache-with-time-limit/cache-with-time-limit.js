var TimeLimitedCache = function() {
    this.cache = new Map();
};

TimeLimitedCache.prototype.set = function(key, value, duration) {
    const alreadyExists = this.cache.has(key);

    if (alreadyExists) {
        clearTimeout(this.cache.get(key).timer);
    }

    const timer = setTimeout(() => {
        this.cache.delete(key);
    }, duration);

    this.cache.set(key, { value, timer });

    return alreadyExists;
};

TimeLimitedCache.prototype.get = function(key) {
    if (!this.cache.has(key)) return -1;

    return this.cache.get(key).value;
};

TimeLimitedCache.prototype.count = function() {
    return this.cache.size;
};