/**
 * @param {number[]} arr
 * @return {boolean}
 */
var uniqueOccurrences = function(arr) {
    const freq = new Map();

    for (const num of arr) {
        freq.set(num, (freq.get(num) || 0) + 1);
    }

    const occurrences = new Set(freq.values());

    return occurrences.size === freq.size;    
};