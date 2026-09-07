var rob = function(nums) {
    if (nums.length === 1) return nums[0];

    function robLinear(arr) {
        let prev2 = 0;
        let prev1 = 0;

        for (const num of arr) {
            const current = Math.max(
                prev1,
                prev2 + num
            );

            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }

    return Math.max(
        robLinear(nums.slice(0, -1)),
        robLinear(nums.slice(1))
    );
};