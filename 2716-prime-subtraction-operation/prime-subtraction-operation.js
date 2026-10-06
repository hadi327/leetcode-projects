var primeSubOperation = function(nums) {
    function isPrime(n) {
        if (n < 2) return false;

        for (let i = 2; i * i <= n; i++) {
            if (n % i === 0) return false;
        }

        return true;
    }

    for (let i = 0; i < nums.length; i++) {
        let prev = i === 0 ? 0 : nums[i - 1];

        // Try the largest possible prime
        for (let p = nums[i] - 1; p >= 2; p--) {
            if (isPrime(p) && nums[i] - p > prev) {
                nums[i] -= p;
                break;
            }
        }

        // If current number isn't greater than previous
        if (nums[i] <= prev) {
            return false;
        }
    }

    return true;
};