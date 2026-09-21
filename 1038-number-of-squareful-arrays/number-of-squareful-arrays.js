var numSquarefulPerms = function(nums) {
    nums.sort((a, b) => a - b);

    const n = nums.length;
    const used = new Array(n).fill(false);
    let answer = 0;

    function isSquare(num) {
        const root = Math.floor(Math.sqrt(num));
        return root * root === num;
    }

    function backtrack(path) {
        if (path.length === n) {
            answer++;
            return;
        }

        for (let i = 0; i < n; i++) {
            if (used[i]) continue;

            // Avoid duplicate permutations
            if (
                i > 0 &&
                nums[i] === nums[i - 1] &&
                !used[i - 1]
            ) {
                continue;
            }

            // Adjacent sum must be a perfect square
            if (
                path.length > 0 &&
                !isSquare(path[path.length - 1] + nums[i])
            ) {
                continue;
            }

            used[i] = true;
            path.push(nums[i]);

            backtrack(path);

            path.pop();
            used[i] = false;
        }
    }

    backtrack([]);

    return answer;
};