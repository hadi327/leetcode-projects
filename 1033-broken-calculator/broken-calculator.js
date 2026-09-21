var brokenCalc = function(startValue, target) {
    let operations = 0;

    while (target > startValue) {
        if (target % 2 === 0) {
            target /= 2;
        } else {
            target++;
        }

        operations++;
    }

    // Once target <= startValue,
    // only -1 operations are needed forward.
    operations += startValue - target;

    return operations;
};