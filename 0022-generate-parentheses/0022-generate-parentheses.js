var generateParenthesis = function(n) {
    const result = [];

    function backtrack(current, open, close) {

        // Complete valid combination
        if (current.length === 2 * n) {
            result.push(current);
            return;
        }

        // Add '(' if we still have some left
        if (open < n) {
            backtrack(current + "(", open + 1, close);
        }

        // Add ')' only if it won't become invalid
        if (close < open) {
            backtrack(current + ")", open, close + 1);
        }
    }

    backtrack("", 0, 0);

    return result;
};