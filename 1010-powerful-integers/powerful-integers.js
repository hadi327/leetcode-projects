var powerfulIntegers = function(x, y, bound) {
    const result = new Set();

    let a = 1;

    while (a <= bound) {
        let b = 1;

        while (a + b <= bound) {
            result.add(a + b);

            if (y === 1) break;

            b *= y;
        }

        if (x === 1) break;

        a *= x;
    }

    return [...result];
};