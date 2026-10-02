var alternateDigitSum = function(n) {
    let digits = n.toString();
    let sum = 0;

    for (let i = 0; i < digits.length; i++) {
        let digit = Number(digits[i]);

        if (i % 2 === 0) {
            sum += digit;
        } else {
            sum -= digit;
        }
    }

    return sum;
};