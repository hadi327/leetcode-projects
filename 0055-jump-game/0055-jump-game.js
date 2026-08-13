var canJump = function(nums) {
    let reach = 0;

    for (let i = 0; i < nums.length; i++) {
        if (i > reach) return false;

        reach = Math.max(reach, i + nums[i]);

        if (reach >= nums.length - 1) return true;
    }

    return true;
};