var getSkyline = function(buildings) {
    const events = [];

    for (const [left, right, height] of buildings) {
        events.push([left, -height]);
        events.push([right, height]);
    }

    events.sort((a, b) => {
        if (a[0] !== b[0]) {
            return a[0] - b[0];
        }

        return a[1] - b[1];
    });

    const result = [];
    const heights = new Map();

    heights.set(0, 1);

    let prevMax = 0;

    function getMax() {
        let max = 0;

        for (const [height, count] of heights) {
            if (count > 0) {
                max = Math.max(max, height);
            }
        }

        return max;
    }

    for (const [x, h] of events) {
        if (h < 0) {
            const height = -h;
            heights.set(
                height,
                (heights.get(height) || 0) + 1
            );
        } else {
            const count = heights.get(h);

            if (count === 1) {
                heights.delete(h);
            } else {
                heights.set(h, count - 1);
            }
        }

        const currentMax = getMax();

        if (currentMax !== prevMax) {
            result.push([x, currentMax]);
            prevMax = currentMax;
        }
    }

    return result;
};