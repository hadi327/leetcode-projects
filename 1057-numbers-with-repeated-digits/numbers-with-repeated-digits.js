var numDupDigitsAtMostN = function(n) {
    const digits = String(n).split("").map(Number);
    const len = digits.length;

    // Count unique-digit numbers with fewer digits
    let unique = 0;

    for (let length = 1; length < len; length++) {
        // First digit: 1-9
        let count = 9;

        // Remaining digits
        for (let j = 1; j < length; j++) {
            count *= (10 - j);
        }

        unique += count;
    }

    // Count unique-digit numbers with same length as n
    const used = new Set();

    for (let i = 0; i < len; i++) {
        const current = digits[i];

        // Digits smaller than current
        let smaller = 0;

        for (let d = (i === 0 ? 1 : 0); d < current; d++) {
            if (!used.has(d)) {
                smaller++;
            }
        }

        // Available choices for this position
        let remaining = len - i - 1;
        let permutations = 1;

        for (let j = 0; j < remaining; j++) {
            permutations *= (9 - i - j);
        }

        unique += smaller * permutations;

        // Repeated digit → stop
        if (used.has(current)) {
            break;
        }

        used.add(current);

        // Last digit processed successfully
        if (i === len - 1) {
            unique++;
        }
    }

    return n - unique;
};