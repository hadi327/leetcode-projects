/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int countBits(int x) {
    int count = 0;

    while (x) {
        count += x & 1;
        x >>= 1;
    }

    return count;
}

char** readBinaryWatch(int turnedOn, int* returnSize) {
    char** answer = malloc(1000 * sizeof(char*));

    int count = 0;

    for (int hour = 0; hour < 12; hour++) {

        for (int minute = 0; minute < 60; minute++) {

            if (countBits(hour) + countBits(minute) == turnedOn) {

                answer[count] = malloc(10 * sizeof(char));

                sprintf(
                    answer[count],
                    "%d:%02d",
                    hour,
                    minute
                );

                count++;
            }
        }
    }

    *returnSize = count;

    return answer;
}