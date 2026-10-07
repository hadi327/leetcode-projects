var topKFrequent = function(words, k) {
    const freq = new Map();

    // Count frequencies
    for (const word of words) {
        freq.set(word, (freq.get(word) || 0) + 1);
    }

    // Convert map to array
    const arr = [...freq.entries()];

    // Sort:
    // 1. Higher frequency first
    // 2. Alphabetical order if frequency is equal
    arr.sort((a, b) => {
        if (a[1] !== b[1]) {
            return b[1] - a[1];
        }

        return a[0].localeCompare(b[0]);
    });

    // Take first k words
    return arr.slice(0, k).map(item => item[0]);
};