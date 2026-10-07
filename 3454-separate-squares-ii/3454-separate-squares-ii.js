var separateSquares = function(squares) {
    const events = [];
    const xs = [];

    for (const [x, y, l] of squares) {
        const x2 = x + l;
        const y2 = y + l;

        xs.push(x, x2);

        // [y, +1] -> square starts
        // [y2, -1] -> square ends
        events.push([y, 1, x, x2]);
        events.push([y2, -1, x, x2]);
    }

    xs.sort((a, b) => a - b);
    const X = [...new Set(xs)];

    const m = X.length - 1;

    // Segment tree
    const count = Array(4 * m).fill(0);
    const length = Array(4 * m).fill(0);

    function update(node, left, right, ql, qr, value) {
        if (ql > right || qr < left) return;

        if (ql <= left && right <= qr) {
            count[node] += value;
        } else {
            const mid = Math.floor((left + right) / 2);

            update(node * 2, left, mid, ql, qr, value);
            update(node * 2 + 1, mid + 1, right, ql, qr, value);
        }

        if (count[node] > 0) {
            length[node] = X[right + 1] - X[left];
        } else if (left === right) {
            length[node] = 0;
        } else {
            length[node] =
                length[node * 2] +
                length[node * 2 + 1];
        }
    }

    // Convert x-coordinate to compressed index
    function getIndex(x) {
        let lo = 0;
        let hi = X.length - 1;

        while (lo <= hi) {
            const mid = Math.floor((lo + hi) / 2);

            if (X[mid] === x) return mid;

            if (X[mid] < x) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return -1;
    }

    // Sort events by y
    events.sort((a, b) => a[0] - b[0]);

    // First calculate total union area
    let totalArea = 0;
    let prevY = events[0][0];

    let i = 0;

    while (i < events.length) {
        const y = events[i][0];

        totalArea += length[1] * (y - prevY);

        while (i < events.length && events[i][0] === y) {
            const [, type, x1, x2] = events[i];

            const l = getIndex(x1);
            const r = getIndex(x2) - 1;

            if (l <= r) {
                update(1, 0, m - 1, l, r, type);
            }

            i++;
        }

        prevY = y;
    }

    const half = totalArea / 2;

    // Reset segment tree
    count.fill(0);
    length.fill(0);

    let area = 0;
    prevY = events[0][0];
    i = 0;

    while (i < events.length) {
        const y = events[i][0];

        const width = length[1];
        const dy = y - prevY;
        const addedArea = width * dy;

        if (area + addedArea >= half) {
            // The answer lies between prevY and y.
            return prevY + (half - area) / width;
        }

        area += addedArea;

        while (i < events.length && events[i][0] === y) {
            const [, type, x1, x2] = events[i];

            const l = getIndex(x1);
            const r = getIndex(x2) - 1;

            if (l <= r) {
                update(1, 0, m - 1, l, r, type);
            }

            i++;
        }

        prevY = y;
    }

    return prevY;
};