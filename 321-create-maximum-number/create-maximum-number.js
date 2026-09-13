let maxNumber = function (nums1, nums2, k) {
    function maxSubsequence(nums, t) {
        let stack = [], drop = nums.length - t;

        for (let num of nums) {
            while (stack.length && stack[stack.length - 1] < num && drop > 0) {
                stack.pop();
                drop--;
            }

            stack.push(num);
        }

        return stack.slice(0, t);
    }

    function merge(a, b) {
        let result = [];
        while (a.length || b.length) {
            if (a > b) result.push(a.shift());
            else result.push(b.shift());
        }

        return result;
    }

    let res = [];
    let start = Math.max(0, k - nums2.length);
    let end = Math.min(k, nums1.length);

    for (let i = start; i <= end; i++) {
        let subseq1 = maxSubsequence(nums1, i);
        let subseq2 = maxSubsequence(nums2, k - i);
        let candidate = merge([...subseq1], [...subseq2]);
        if (candidate > res) res = candidate;
    }

    return res;
}