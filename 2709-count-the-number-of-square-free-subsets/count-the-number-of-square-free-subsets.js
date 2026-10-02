/**
 * @param {number[]} nums
 * @return {number}
 */
var squareFreeSubsets = function(nums) {
    const bads = new Set([4, 8, 9, 12, 16, 18, 20, 24, 25, 27, 28])
    const primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
    const squares = primes.map(prime => prime ** 2)

    function haveConflict(a, b) {
        const product = a * b
        return squares.some(square => product % square === 0)
    }

    const maxVal = 30
    const val2freq = new Array(1 + maxVal).fill(0)
    for (const val of nums) {
        if (bads.has(val))  continue
        val2freq[val]++
    }

    const items = []
    for (const pair of val2freq.entries()) {
        const [val, freq] = pair
        if (freq > 0)
            items.push(pair)
    }
    
    
    const len = items.length
    const modMe = 10 ** 9 + 7
    const modMeBigInt = BigInt(modMe)
    function dfs(fromIndex, productSF) {
        if (fromIndex === len)
            return 1
        
        const item = items[fromIndex]
        const [val, freq] = item

        let result = dfs(fromIndex + 1, productSF) % modMe // dont choose
        let subresult = 0 // choose it
        if (!haveConflict(productSF, val)) {
            const freqBigInt = BigInt(freq)
            const factor = (val !== 1) ? freqBigInt : (2n ** freqBigInt - 1n)
            subresult =
                factor * BigInt(dfs(fromIndex + 1, productSF * val)) % modMeBigInt
            subresult = Number(subresult)
        }
        result = (result + subresult) % modMe

        return result
    }


    
    let result = dfs(0, 1)
    result = (result - 1 + modMe) % modMe
    return result
};