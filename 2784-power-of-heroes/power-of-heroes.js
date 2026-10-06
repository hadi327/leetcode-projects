var sumOfPower = function(nums) {
    const MOD = 1000000007n;

    nums.sort((a, b) => a - b);

    let prefix = 0n;
    let answer = 0n;

    for (let num of nums) {
        let x = BigInt(num);

        let contribution = x * x % MOD;
        contribution = contribution * ((x + prefix) % MOD);
        contribution %= MOD;

        answer = (answer + contribution) % MOD;

        prefix = (prefix * 2n + x) % MOD;
    }

    return Number(answer);
};