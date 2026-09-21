/**
 * @param {number} label
 * @return {number[]}
 */
var pathInZigZagTree = function(label) {
    let level = 0, res = [label];
    // get label's level
    while(label = parseInt(label / 2)) {
        level++;
    }
    
    // 1. every level's number is in [Math.pow(2, level), Math.pow(2, level + 1) - 1]
    // 2. node[level - 1] = parseInt(res[level] / 2)
    // 3. res[level - 1] = (Math.pow(2, level) + Math.pow(2, level + 1) - 1) - node[level - 1] is the parent node we need;
    for(let i = level - 1; i >= 0; i--) {
        let sum = (2 ** i) + (2 ** (i + 1)) - 1;
        let val = parseInt(res[0] / 2);
        res.unshift(sum - val);
    }
    return res;
};