var threeEqualParts = function(arr) {
    let ones = arr.reduce((sum, x) => sum + x, 0);

    // All zeros
    if (ones === 0) {
        return [0, 2];
    }

    // Cannot divide the 1s equally
    if (ones % 3 !== 0) {
        return [-1, -1];
    }

    let onesPerPart = ones / 3;

    let first = -1;
    let second = -1;
    let third = -1;

    let count = 0;

    for (let i = 0; i < arr.length; i++) {
        if (arr[i] === 1) {
            count++;

            if (count === 1) {
                first = i;
            }

            if (count === onesPerPart + 1) {
                second = i;
            }

            if (count === 2 * onesPerPart + 1) {
                third = i;
                break;
            }
        }
    }

    // Number of trailing zeros.
    let trailingZeros = arr.length - 1;

    while (
        trailingZeros >= 0 &&
        arr[trailingZeros] === 0
    ) {
        trailingZeros--;
    }

    trailingZeros =
        arr.length - 1 - trailingZeros;

    // The three parts need enough space
    if (
        second - first < trailingZeros ||
        third - second < trailingZeros ||
        arr.length - third < trailingZeros
    ) {
        return [-1, -1];
    }

    // Compare the three parts.
    let i = first;
    let j = second;
    let k = third;

    while (k < arr.length) {
        if (
            arr[i] !== arr[j] ||
            arr[j] !== arr[k]
        ) {
            return [-1, -1];
        }

        i++;
        j++;
        k++;
    }

    return [
        i - 1,
        j
    ];
};