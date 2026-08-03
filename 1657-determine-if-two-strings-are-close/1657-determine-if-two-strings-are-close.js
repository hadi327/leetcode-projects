/**
 * @param {string} word1
 * @param {string} word2
 * @return {boolean}
 */
var closeStrings = function(word1, word2) {
     if (word1.length !== word2.length) {
        return false;
    }

    const freq1 = new Map();
    const freq2 = new Map();

    for (const ch of word1) {
        freq1.set(ch, (freq1.get(ch) || 0) + 1);
    }

    for (const ch of word2) {
        freq2.set(ch, (freq2.get(ch) || 0) + 1);
    }

    if (freq1.size !== freq2.size) {
        return false;
    }

    for (const ch of freq1.keys()) {
        if (!freq2.has(ch)) {
            return false;
        }
    }

    const count1 = [...freq1.values()].sort((a, b) => a - b);
    const count2 = [...freq2.values()].sort((a, b) => a - b);

    for (let i = 0; i < count1.length; i++) {
        if (count1[i] !== count2[i]) {
            return false;
        }
    }

    return true;
};