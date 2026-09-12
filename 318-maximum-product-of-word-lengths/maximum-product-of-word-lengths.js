var maxProduct = function(words) {
    const n = words.length;
    const masks = new Array(n).fill(0);

    for (let i = 0; i < n; i++) {
        for (const ch of words[i]) {
            masks[i] |= 1 << (ch.charCodeAt(0) - 97);
        }
    }

    let answer = 0;

    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            // No common characters
            if ((masks[i] & masks[j]) === 0) {
                answer = Math.max(
                    answer,
                    words[i].length * words[j].length
                );
            }
        }
    }

    return answer;
};