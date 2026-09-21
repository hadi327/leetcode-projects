var minAreaFreeRect = function(points) {
    const n = points.length;
    const groups = new Map();

    // Group diagonals by midpoint and squared length
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            const [x1, y1] = points[i];
            const [x2, y2] = points[j];

            const midX = x1 + x2;
            const midY = y1 + y2;

            const dx = x1 - x2;
            const dy = y1 - y2;

            const dist = dx * dx + dy * dy;

            const key = `${midX},${midY},${dist}`;

            if (!groups.has(key)) {
                groups.set(key, []);
            }

            groups.get(key).push([i, j]);
        }
    }

    let answer = Infinity;

    for (const diagonals of groups.values()) {
        for (let a = 0; a < diagonals.length; a++) {
            for (let b = a + 1; b < diagonals.length; b++) {
                const [i, j] = diagonals[a];
                const [k, l] = diagonals[b];

                const [x1, y1] = points[i];
                const [x2, y2] = points[k];
                const [x3, y3] = points[l];

                // Adjacent sides from point i
                const side1 = Math.hypot(x1 - x2, y1 - y2);
                const side2 = Math.hypot(x1 - x3, y1 - y3);

                const area = side1 * side2;

                answer = Math.min(answer, area);
            }
        }
    }

    return answer === Infinity ? 0 : answer;
};