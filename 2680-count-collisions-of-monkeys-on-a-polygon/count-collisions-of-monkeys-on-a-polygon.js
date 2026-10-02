var monkeyMove = function(n) {
    const MOD = 1000000007n;

    function power(base, exp) {
        let result = 1n;

        while (exp > 0n) {
            if (exp % 2n === 1n) {
                result = (result * base) % MOD;
            }

            base = (base * base) % MOD;
            exp = exp / 2n;
        }

        return result;
    }

    return Number((power(2n, BigInt(n)) - 2n + MOD) % MOD);
};