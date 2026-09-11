int lengthOfLastWord(char* s) {
    int i = 0;
    int length = 0;

    // Find the end of the string
    while (s[i] != '\0') {
        i++;
    }

    // Move backwards, skipping trailing spaces
    i--;

    while (i >= 0 && s[i] == ' ') {
        i--;
    }

    // Count the last word
    while (i >= 0 && s[i] != ' ') {
        length++;
        i--;
    }

    return length;
}