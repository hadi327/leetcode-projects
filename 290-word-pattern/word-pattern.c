#include <stdbool.h>
#include <string.h>

bool wordPattern(char* pattern, char* s) {
    char* words[300];
    int wordCount = 0;

    // Split s into words
    char* token = strtok(s, " ");

    while (token != NULL) {
        words[wordCount++] = token;
        token = strtok(NULL, " ");
    }

    int patternLength = strlen(pattern);

    // Number of words must equal number of pattern characters
    if (patternLength != wordCount)
        return false;

    // Check one-to-one mapping
    for (int i = 0; i < patternLength; i++) {

        for (int j = 0; j < i; j++) {

            // Same pattern character must map to same word
            if (pattern[i] == pattern[j]) {
                if (strcmp(words[i], words[j]) != 0)
                    return false;
            }

            // Different pattern characters cannot map to same word
            if (pattern[i] != pattern[j]) {
                if (strcmp(words[i], words[j]) == 0)
                    return false;
            }
        }
    }

    return true;
}