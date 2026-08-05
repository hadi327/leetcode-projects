/**
 * @param {number} a
 * @param {number} b
 * @param {number} c
 * @return {number}
 */
var minFlips = function(a, b, c) {
    let flips = 0;

    while (a > 0 || b > 0 || c > 0) {
        let bitA = a & 1;
        let bitB = b & 1;
        let bitC = c & 1;

        if (bitC === 0) {
            flips += bitA + bitB;
        } else {
            if (bitA === 0 && bitB === 0) {
                flips++;
            }
        }

        a >>= 1;
        b >>= 1;
        c >>= 1;
    }

    return flips;
};