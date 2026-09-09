function flat(arr, n) {
    function flatten(array, depth) {
        if (depth === 0) return array;

        const result = [];

        for (const item of array) {
            if (Array.isArray(item)) {
                result.push(...flatten(item, depth - 1));
            } else {
                result.push(item);
            }
        }

        return result;
    }

    return flatten(arr, n);
}