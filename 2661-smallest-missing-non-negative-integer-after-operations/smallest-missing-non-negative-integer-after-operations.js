var findSmallestInteger = function(nums, value) {
    let count = new Array(value).fill(0);

    for (let num of nums) {
        let rem = ((num % value) + value) % value;
        count[rem]++;
    }

    let mex = 0;

    while (count[mex % value] > 0) {
        count[mex % value]--;
        mex++;
    }

    return mex;
};