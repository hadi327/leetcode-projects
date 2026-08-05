/**
 * @param {string[]} products
 * @param {string} searchWord
 * @return {string[][]}
 */
var suggestedProducts = function(products, searchWord) {
    products.sort();

    const ans = [];
    let prefix = "";

    for (const ch of searchWord) {
        prefix += ch;

        let left = 0;
        let right = products.length - 1;

        // Find first product >= prefix
        while (left <= right) {
            const mid = Math.floor((left + right) / 2);

            if (products[mid] >= prefix) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        const suggestions = [];
        for (let i = left; i < Math.min(left + 3, products.length); i++) {
            if (products[i].startsWith(prefix)) {
                suggestions.push(products[i]);
            } else {
                break;
            }
        }

        ans.push(suggestions);
    }

    return ans;
};