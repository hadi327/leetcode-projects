var palindromePairs = function(words) {
    const map = new Map();

    for (let i = 0; i < words.length; i++) {
        map.set(words[i], i);
    }

    const result = [];

    function isPalindrome(str, left, right) {
        while (left < right) {
            if (str[left] !== str[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    for (let i = 0; i < words.length; i++) {
        const word = words[i];

        for (let j = 0; j <= word.length; j++) {
            const left = word.slice(0, j);
            const right = word.slice(j);

            // left + reverse(left) forms palindrome
            if (isPalindrome(word, j, word.length - 1)) {
                const reversed = left.split("").reverse().join("");

                if (map.has(reversed) && map.get(reversed) !== i) {
                    result.push([
                        i,
                        map.get(reversed)
                    ]);
                }
            }

            // reverse(right) + right forms palindrome
            if (
                j > 0 &&
                isPalindrome(word, 0, j - 1)
            ) {
                const reversed = right.split("").reverse().join("");

                if (map.has(reversed) && map.get(reversed) !== i) {
                    result.push([
                        map.get(reversed),
                        i
                    ]);
                }
            }
        }
    }

    return result;
};