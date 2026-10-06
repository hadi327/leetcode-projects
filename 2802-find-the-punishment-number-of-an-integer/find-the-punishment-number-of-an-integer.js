var punishmentNumber = function(n) {
    let answer = 0;

    function canSplit(str, index, target, sum) {
        if (index === str.length) {
            return sum === target;
        }

        let num = 0;

        for (let i = index; i < str.length; i++) {
            num = num * 10 + Number(str[i]);

            if (sum + num > target) {
                break;
            }

            if (canSplit(str, i + 1, target, sum + num)) {
                return true;
            }
        }

        return false;
    }

    for (let i = 1; i <= n; i++) {
        let square = i * i;

        if (canSplit(square.toString(), 0, i, 0)) {
            answer += square;
        }
    }

    return answer;
};