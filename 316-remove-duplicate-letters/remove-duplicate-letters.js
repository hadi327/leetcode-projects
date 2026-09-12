var removeDuplicateLetters = function(s) {
    const last = new Array(26).fill(0);
    const used = new Array(26).fill(false);

    for (let i = 0; i < s.length; i++) {
        last[s.charCodeAt(i) - 97] = i;
    }

    const stack = [];

    for (let i = 0; i < s.length; i++) {
        const index = s.charCodeAt(i) - 97;

        if (used[index]) {
            continue;
        }

        while (
            stack.length > 0 &&
            stack[stack.length - 1] > s[i] &&
            last[
                stack[stack.length - 1].charCodeAt(0) - 97
            ] > i
        ) {
            const removed = stack.pop();
            used[removed.charCodeAt(0) - 97] = false;
        }

        stack.push(s[i]);
        used[index] = true;
    }

    return stack.join("");
};