var kthLargestNumber = function(nums, k) {
    nums.sort((a, b) => {
        // Longer number = larger number
        if (a.length !== b.length) {
            return b.length - a.length;
        }

        // Same length → lexicographical comparison
        if (a === b) return 0;

        return a > b ? -1 : 1;
    });

    return nums[k - 1];
};