/**
 * @param {number[]} prices
 * @param {number} fee
 * @return {number}
 */
var maxProfit = function(prices, fee) {
    let hold = -prices[0];
    let cash = 0;

    for (let i = 1; i < prices.length; i++) {
        let prevCash = cash;

        cash = Math.max(cash, hold + prices[i] - fee);
        hold = Math.max(hold, prevCash - prices[i]);
    }

    return cash;
};