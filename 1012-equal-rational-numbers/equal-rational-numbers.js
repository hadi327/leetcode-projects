var isRationalEqual = function(s, t) {
    function toFraction(str) {
        let [integer, decimal = ""] = str.split(".");

        let repeatStart = decimal.indexOf("(");

        if (repeatStart === -1) {
            const digits = decimal.length;
            const denominator = 10 ** digits;

            const numerator =
                Number(integer) * denominator +
                (decimal ? Number(decimal) : 0);

            return [numerator, denominator];
        }

        const nonRepeat = decimal.slice(0, repeatStart);
        const repeat = decimal.slice(
            repeatStart + 1,
            decimal.length - 1
        );

        const m = nonRepeat.length;
        const n = repeat.length;

        const powM = 10 ** m;
        const powN = 10 ** n;

        // Example:
        // 0.12(34)
        //
        // = 12/100 + 34/(100 * 99)

        const denominator = powM * (powN - 1);

        const numerator =
            Number(integer) * denominator +
            Number(nonRepeat || 0) * (powN - 1) +
            Number(repeat);

        return [numerator, denominator];
    }

    function gcd(a, b) {
        while (b !== 0) {
            [a, b] = [b, a % b];
        }
        return a;
    }

    function normalize([num, den]) {
        const g = gcd(num, den);
        return [num / g, den / g];
    }

    const a = normalize(toFraction(s));
    const b = normalize(toFraction(t));

    return a[0] === b[0] && a[1] === b[1];
};