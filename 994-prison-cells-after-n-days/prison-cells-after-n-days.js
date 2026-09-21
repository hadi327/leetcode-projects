var prisonAfterNDays = function(cells, n) {
    const seen = new Map();

    while (n > 0) {
        const state = cells.join("");

        // Cycle detected
        if (seen.has(state)) {
            const cycleLength = seen.get(state) - n;
            n %= cycleLength;
        }

        seen.set(state, n);

        if (n === 0) break;

        const next = new Array(8).fill(0);

        for (let i = 1; i < 7; i++) {
            next[i] = cells[i - 1] === cells[i + 1] ? 1 : 0;
        }

        cells = next;
        n--;
    }

    return cells;
};