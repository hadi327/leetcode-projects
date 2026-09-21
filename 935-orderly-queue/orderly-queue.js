var orderlyQueue = function(s, k) {
    if (k > 1) {
        return s.split("").sort().join("");
    }

    let answer = s;

    for (let i = 1; i < s.length; i++) {
        let rotation = s.slice(i) + s.slice(0, i);

        if (rotation < answer) {
            answer = rotation;
        }
    }

    return answer;
};