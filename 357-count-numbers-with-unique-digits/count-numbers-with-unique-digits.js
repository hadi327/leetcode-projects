var countNumbersWithUniqueDigits = function(n) {
    if (n === 0) {
        return 1;
    }

    n = Math.min(n, 10);

    let answer = 10;
    let unique = 9;
    let available = 9;

    for (let digits = 2; digits <= n; digits++) {
        unique *= available;
        answer += unique;
        available--;
    }

    return answer;
};