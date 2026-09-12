var addOperators = function(num, target) {
    const result = [];

    function backtrack(index, expression, value, previous) {
        // Entire string is used
        if (index === num.length) {
            if (value === target) {
                result.push(expression);
            }
            return;
        }

        for (let i = index; i < num.length; i++) {
            // Numbers cannot have leading zeros
            if (i > index && num[index] === '0') {
                break;
            }

            const current = num.substring(index, i + 1);
            const currentValue = Number(current);

            // First number
            if (index === 0) {
                backtrack(
                    i + 1,
                    current,
                    currentValue,
                    currentValue
                );
            } else {
                // Addition
                backtrack(
                    i + 1,
                    expression + "+" + current,
                    value + currentValue,
                    currentValue
                );

                // Subtraction
                backtrack(
                    i + 1,
                    expression + "-" + current,
                    value - currentValue,
                    -currentValue
                );

                // Multiplication
                // Remove previous contribution and replace it
                // with previous * current
                backtrack(
                    i + 1,
                    expression + "*" + current,
                    value - previous + previous * currentValue,
                    previous * currentValue
                );
            }
        }
    }

    backtrack(0, "", 0, 0);

    return result;
};