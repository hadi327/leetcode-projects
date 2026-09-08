var findDuplicate = function(nums) {
    let slow = nums[0];
    let fast = nums[0];

    // Find intersection
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow !== fast);

    // Find cycle entrance
    slow = nums[0];

    while (slow !== fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
};