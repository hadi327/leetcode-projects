var maxProfit = function(prices) {
    let hold = -prices[0];
    let sold = 0;
    let rest = 0;

    for (let i = 1; i < prices.length; i++) {
        const prevHold = hold;
        const prevSold = sold;
        const prevRest = rest;

        hold = Math.max(
            prevHold,
            prevRest - prices[i]
        );

        sold = prevHold + prices[i];

        rest = Math.max(
            prevRest,
            prevSold
        );
    }

    return Math.max(sold, rest);
};