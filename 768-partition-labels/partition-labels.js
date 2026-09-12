/**
 * @param {string} s
 * @return {number[]}
 */
var partitionLabels = function (s) {
    let first = Array(26).fill(-1);
    let last = Array(26).fill(-1)

    for (let i = 0; i < s.length; i++) {
        let curr = s.charCodeAt(i) - 97
        if (first[curr] === -1) {
            first[curr] = i;
        }
        last[curr] = i;
    }

    const intervals = [];
    for (let i = 0; i < 26; i++) {
        if (first[i] === -1) continue;
        intervals.push([first[i], last[i]]);
    }

    intervals.sort((a, b) => a[0] - b[0]);

    let ans = [intervals[0]];

    for (let i = 1; i < intervals.length; i++) {
        if (intervals[i][0] <= ans[ans.length - 1][1]) {
            ans[ans.length - 1][1] = Math.max(ans[ans.length - 1][1], intervals[i][1])
        } else {
            ans.push(intervals[i]);
        }
    }

    return ans.map(([a, b]) => b - a + 1);
};