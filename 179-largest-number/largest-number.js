var largestNumber = function(nums) {
    nums.sort((a, b) => {
        const x = String(a) + String(b);
        const y = String(b) + String(a);

        return y.localeCompare(x);
    });

    if (nums[0] === 0) {
        return "0";
    }

    return nums.join('');
};