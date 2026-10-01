/**
 * @param {number} targetX
 * @param {number} targetY
 * @return {boolean}
 */
var isReachable = function(targetX, targetY) {
    function gcd(m, n) {
        if (m > n)  return gcd(n, m)
        if (m === 0)    return n
        return gcd(n % m, m)
    }


    const g = gcd(targetX, targetY)
    return (g & (g - 1)) === 0
};