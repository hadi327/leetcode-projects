var hasGroupsSizeX = function(deck) {
    let count = new Map();

    for (let card of deck) {
        count.set(card, (count.get(card) || 0) + 1);
    }

    function gcd(a, b) {
        while (b !== 0) {
            [a, b] = [b, a % b];
        }

        return a;
    }

    let groupSize = 0;

    for (let frequency of count.values()) {
        groupSize = gcd(groupSize, frequency);

        if (groupSize < 2) {
            return false;
        }
    }

    return groupSize >= 2;
};