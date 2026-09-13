var superPow = function(a, b) {
    const MOD = 1337;

    function modPow(x, n) {
        let result = 1;
        x %= MOD;

        while (n > 0) {
            if (n % 2 === 1) {
                result = (result * x) % MOD;
            }

            x = (x * x) % MOD;
            n = Math.floor(n / 2);
        }

        return result;
    }

    let result = 1;

    for (const digit of b) {
        result =
            (modPow(result, 10) * modPow(a, digit)) % MOD;
    }

    return result;
};