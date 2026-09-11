#include <stdlib.h>
#include <string.h>

char* reverseWords(char* s) {
    int n = strlen(s);

    // Allocate result
    char* result = (char*)malloc((n + 1) * sizeof(char));
    int pos = 0;
    int i = n - 1;

    while (i >= 0) {

        // Skip spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        if (i < 0)
            break;

        // Find the beginning of the word
        int end = i;

        while (i >= 0 && s[i] != ' ') {
            i--;
        }

        // Add a space between words
        if (pos > 0) {
            result[pos++] = ' ';
        }

        // Copy the word
        for (int j = i + 1; j <= end; j++) {
            result[pos++] = s[j];
        }
    }

    result[pos] = '\0';

    return result;
}