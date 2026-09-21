var sumSubseqWidths = function(nums) {
    const MOD = 1000000007;
    const n = nums.length;

    nums.sort((a, b) => a - b);

    let powers = new Array(n);
    powers[0] = 1;

    for (let i = 1; i < n; i++) {
        powers[i] = (powers[i - 1] * 2) % MOD;
    }

    let answer = 0;

    for (let i = 0; i < n; i++) {
        let maxContribution = powers[i];
        let minContribution = powers[n - 1 - i];

        answer += nums[i] * (maxContribution - minContribution);
        answer %= MOD;
    }

    return (answer + MOD) % MOD;
};