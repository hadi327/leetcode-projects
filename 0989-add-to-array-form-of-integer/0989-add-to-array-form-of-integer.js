var addToArrayForm = function(num, k) {
    let i = num.length - 1;

    while (i >= 0 || k > 0) {
        if (i >= 0) {
            k += num[i];
            num[i] = k % 10;
            k = Math.floor(k / 10);
            i--;
        } else {
            num.unshift(k % 10);
            k = Math.floor(k / 10);
        }
    }

    return num;
};