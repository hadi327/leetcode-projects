var kItemsWithMaximumSum = function(numOnes, numZeros, numNegOnes, k) {
    let sum = 0;

    // Take as many 1s as possible
    let ones = Math.min(k, numOnes);
    sum += ones;
    k -= ones;

    // Take 0s (no effect on sum)
    let zeros = Math.min(k, numZeros);
    k -= zeros;

    // Remaining items must be -1
    sum -= k;

    return sum;
};