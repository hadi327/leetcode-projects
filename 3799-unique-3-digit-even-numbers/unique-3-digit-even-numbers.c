int totalNumbers(int* digits, int digitsSize) {
    int count = 0;

    for (int num = 100; num <= 999; num++) {
        if (num % 2 != 0)
            continue;

        int a = num / 100;
        int b = (num / 10) % 10;
        int c = num % 10;

        int freq[10] = {0};

        for (int i = 0; i < digitsSize; i++) {
            freq[digits[i]]++;
        }

        if (freq[a] == 0)
            continue;

        freq[a]--;

        if (freq[b] == 0)
            continue;

        freq[b]--;

        if (freq[c] == 0)
            continue;

        count++;
    }

    return count;
}