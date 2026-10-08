var removeOuterParentheses = function(s) {
    let depth = 0;
    let result = "";

    for (const ch of s) {
        if (ch === "(") {
            // If depth > 0, this is NOT an outermost '('
            if (depth > 0) {
                result += ch;
            }

            depth++;
        } else {
            depth--;

            // If depth > 0, this is NOT an outermost ')'
            if (depth > 0) {
                result += ch;
            }
        }
    }

    return result;
};