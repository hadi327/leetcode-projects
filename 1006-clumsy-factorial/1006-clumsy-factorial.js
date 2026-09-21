var clumsy = function(n) {
    let stack = [n];
    let op = 0; // 0 = *, 1 = /, 2 = +, 3 = -

    for (let x = n - 1; x >= 1; x--) {
        if (op === 0) {
            stack[stack.length - 1] *= x;
        } 
        else if (op === 1) {
            stack[stack.length - 1] = Math.trunc(
                stack[stack.length - 1] / x
            );
        } 
        else if (op === 2) {
            stack.push(x);
        } 
        else {
            stack.push(-x);
        }

        op = (op + 1) % 4;
    }

    return stack.reduce((sum, value) => sum + value, 0);
};