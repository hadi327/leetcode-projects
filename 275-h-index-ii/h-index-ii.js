var hIndex = function(citations) {
    let n = citations.length;

    let left = 0;
    let right = n - 1;

    while (left <= right) {
        let mid = Math.floor((left + right) / 2);

        let papers = n - mid;

        if (citations[mid] >= papers) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return n - left;
};