var canMeasureWater = function(x, y, target) {
    if (target > x + y) {
        return false;
    }

    if (target === 0) {
        return true;
    }

    function gcd(a, b) {
        while (b !== 0) {
            [a, b] = [b, a % b];
        }

        return a;
    }

    return target % gcd(x, y) === 0;
};