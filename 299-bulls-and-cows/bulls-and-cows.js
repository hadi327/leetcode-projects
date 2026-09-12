var getHint = function(secret, guess) {
    let bulls = 0;
    let cows = 0;

    const secretCount = new Array(10).fill(0);
    const guessCount = new Array(10).fill(0);

    // Find bulls and count unmatched digits
    for (let i = 0; i < secret.length; i++) {
        if (secret[i] === guess[i]) {
            bulls++;
        } else {
            secretCount[Number(secret[i])]++;
            guessCount[Number(guess[i])]++;
        }
    }

    // Find cows
    for (let i = 0; i < 10; i++) {
        cows += Math.min(secretCount[i], guessCount[i]);
    }

    return bulls + "A" + cows + "B";
};