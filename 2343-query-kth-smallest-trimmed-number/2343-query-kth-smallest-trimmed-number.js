var smallestTrimmedNumbers = function(nums, queries) {
    let answer = [];

    for (let [k, trim] of queries) {
        let arr = [];

        for (let i = 0; i < nums.length; i++) {
            let trimmed = nums[i].slice(-trim);

            arr.push([trimmed, i]);
        }

        arr.sort((a, b) => {
            if (a[0] === b[0]) {
                return a[1] - b[1];
            }

            return a[0] < b[0] ? -1 : 1;
        });

        answer.push(arr[k - 1][1]);
    }

    return answer;
};