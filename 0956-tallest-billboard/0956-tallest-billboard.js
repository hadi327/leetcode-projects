var tallestBillboard = function(rods) {
    let dp = new Map();

    // Difference 0 with total height 0
    dp.set(0, 0);

    for (let rod of rods) {
        let current = new Map(dp);

        for (let [diff, height] of dp) {
            // Put rod on the taller side
            let newDiff = diff + rod;
            current.set(
                newDiff,
                Math.max(current.get(newDiff) || 0, height)
            );

            // Put rod on the shorter side
            newDiff = Math.abs(diff - rod);

            let newHeight = height + Math.min(diff, rod);

            current.set(
                newDiff,
                Math.max(current.get(newDiff) || 0, newHeight)
            );
        }

        dp = current;
    }

    return dp.get(0);
};