/**
 * @param {number} n
 * @param {number} time
 * @return {number}
 */
var passThePillow = function(n, time) {
    let div = Math.floor(time / (n - 1));
    let rem = time % (n - 1);

    if (rem === 0) {
        if (div % 2 === 0) {
            return 1; // Returns to the first person if even division
        } else {
            return n; // Returns to the last person if odd division
        }
    } else {
        if (div % 2 === 0) {
            return 1 + rem; // Move forward if even division
        } else {
            return n - rem; // Move backward if odd division
        }
    }
};