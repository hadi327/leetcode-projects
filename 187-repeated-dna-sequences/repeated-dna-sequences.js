var findRepeatedDnaSequences = function(s) {
    const seen = new Set();
    const repeated = new Set();

    for (let i = 0; i + 10 <= s.length; i++) {
        const sub = s.substring(i, i + 10);

        if (seen.has(sub)) {
            repeated.add(sub);
        } else {
            seen.add(sub);
        }
    }

    return [...repeated];
};