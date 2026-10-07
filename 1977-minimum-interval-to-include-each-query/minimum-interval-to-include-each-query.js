var minInterval = function(intervals, queries) {
    // Sort intervals by starting point
    intervals.sort((a, b) => a[0] - b[0]);

    // Keep original query positions
    const sortedQueries = queries
        .map((value, index) => [value, index])
        .sort((a, b) => a[0] - b[0]);

    const answer = Array(queries.length).fill(-1);

    // Min heap:
    // [interval length, right endpoint]
    const heap = [];

    function push(item) {
        heap.push(item);

        let i = heap.length - 1;

        while (i > 0) {
            const parent = Math.floor((i - 1) / 2);

            if (heap[parent][0] <= heap[i][0]) break;

            [heap[parent], heap[i]] = [heap[i], heap[parent]];
            i = parent;
        }
    }

    function pop() {
        const top = heap[0];
        const last = heap.pop();

        if (heap.length > 0) {
            heap[0] = last;

            let i = 0;

            while (true) {
                let smallest = i;
                const left = 2 * i + 1;
                const right = 2 * i + 2;

                if (
                    left < heap.length &&
                    heap[left][0] < heap[smallest][0]
                ) {
                    smallest = left;
                }

                if (
                    right < heap.length &&
                    heap[right][0] < heap[smallest][0]
                ) {
                    smallest = right;
                }

                if (smallest === i) break;

                [heap[i], heap[smallest]] =
                    [heap[smallest], heap[i]];

                i = smallest;
            }
        }

        return top;
    }

    let i = 0;

    for (const [query, index] of sortedQueries) {

        // Add every interval that starts before or at query
        while (
            i < intervals.length &&
            intervals[i][0] <= query
        ) {
            const [left, right] = intervals[i];

            const length = right - left + 1;

            push([length, right]);

            i++;
        }

        // Remove intervals that don't contain query anymore
        while (
            heap.length > 0 &&
            heap[0][1] < query
        ) {
            pop();
        }

        // Smallest valid interval is on top
        if (heap.length > 0) {
            answer[index] = heap[0][0];
        }
    }

    return answer;
};