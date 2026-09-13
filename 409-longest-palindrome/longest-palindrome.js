var longestPalindrome = function(s) {
    const count = new Map();

    for (const ch of s) {
        count.set(ch, (count.get(ch) || 0) + 1);
    }

    let length = 0;
    let hasOdd = false;

    for (const freq of count.values()) {
        length += Math.floor(freq / 2) * 2;

        if (freq % 2 === 1) {
            hasOdd = true;
        }
    }

    if (hasOdd) {
        length++;
    }

    return length;
};