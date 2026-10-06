var diagonalPrime = function(nums) {
    let n = nums.length;
    let answer = 0;

    function isPrime(num) {
        if (num < 2) return false;

        for (let i = 2; i * i <= num; i++) {
            if (num % i === 0) {
                return false;
            }
        }

        return true;
    }

    for (let i = 0; i < n; i++) {
        // Main diagonal
        if (isPrime(nums[i][i])) {
            answer = Math.max(answer, nums[i][i]);
        }

        // Secondary diagonal
        if (isPrime(nums[i][n - 1 - i])) {
            answer = Math.max(answer, nums[i][n - 1 - i]);
        }
    }

    return answer;
};