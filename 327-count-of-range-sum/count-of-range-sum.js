var countRangeSum = function(nums, lower, upper) {
    const prefix = new Array(nums.length + 1).fill(0);

    for (let i = 0; i < nums.length; i++) {
        prefix[i + 1] = prefix[i] + nums[i];
    }

    function mergeSort(left, right) {
        if (right - left <= 1) {
            return 0;
        }

        const mid = Math.floor((left + right) / 2);

        let count =
            mergeSort(left, mid) +
            mergeSort(mid, right);

        let j = mid;
        let k = mid;

        for (let i = left; i < mid; i++) {
            while (
                k < right &&
                prefix[k] - prefix[i] < lower
            ) {
                k++;
            }

            while (
                j < right &&
                prefix[j] - prefix[i] <= upper
            ) {
                j++;
            }

            count += j - k;
        }

        const temp = [];
        let i = left;
        j = mid;

        while (i < mid && j < right) {
            if (prefix[i] <= prefix[j]) {
                temp.push(prefix[i++]);
            } else {
                temp.push(prefix[j++]);
            }
        }

        while (i < mid) {
            temp.push(prefix[i++]);
        }

        while (j < right) {
            temp.push(prefix[j++]);
        }

        for (let x = 0; x < temp.length; x++) {
            prefix[left + x] = temp[x];
        }

        return count;
    }

    return mergeSort(0, prefix.length);
};