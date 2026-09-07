var fractionToDecimal = function(numerator, denominator) {
    if (numerator === 0) return "0";

    let result = "";

    if (
        (numerator < 0) !== (denominator < 0)
    ) {
        result += "-";
    }

    let num = Math.abs(numerator);
    let den = Math.abs(denominator);

    result += Math.floor(num / den);

    let remainder = num % den;

    if (remainder === 0) {
        return result;
    }

    result += ".";

    const seen = new Map();

    while (remainder !== 0) {
        if (seen.has(remainder)) {
            const index = seen.get(remainder);

            result =
                result.slice(0, index) +
                "(" +
                result.slice(index) +
                ")";

            return result;
        }

        seen.set(remainder, result.length);

        remainder *= 10;

        result += Math.floor(remainder / den);
        remainder %= den;
    }

    return result;
};