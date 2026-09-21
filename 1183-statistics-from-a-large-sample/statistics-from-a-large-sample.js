var sampleStats = function(count) {
    let total = 0;
    let sum = 0;

    let min = -1;
    let max = -1;

    let mode = 0;
    let maxFreq = 0;

    // Find min, max, mean, mode
    for (let i = 0; i < count.length; i++) {
        if (count[i] > 0) {
            if (min === -1) {
                min = i;
            }

            max = i;

            total += count[i];
            sum += i * count[i];

            if (count[i] > maxFreq) {
                maxFreq = count[i];
                mode = i;
            }
        }
    }

    const mean = sum / total;

    // Find median
    const mid1 = Math.floor((total + 1) / 2);
    const mid2 = Math.floor((total + 2) / 2);

    let median1 = -1;
    let median2 = -1;

    let prefix = 0;

    for (let i = 0; i < count.length; i++) {
        prefix += count[i];

        if (median1 === -1 && prefix >= mid1) {
            median1 = i;
        }

        if (median2 === -1 && prefix >= mid2) {
            median2 = i;
            break;
        }
    }

    const median = (median1 + median2) / 2;

    return [min, max, mean, median, mode];
};