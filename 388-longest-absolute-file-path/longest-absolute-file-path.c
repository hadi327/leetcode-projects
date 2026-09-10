int lengthLongestPath(char* input) {
    int len[10005] = {0};
    int maxLen = 0;

    char* p = input;

    while (*p != '\0') {
        int depth = 0;

        while (*p == '\t') {
            depth++;
            p++;
        }

        int nameLen = 0;
        int isFile = 0;

        while (*p != '\n' && *p != '\0') {
            if (*p == '.')
                isFile = 1;

            nameLen++;
            p++;
        }

        if (depth == 0)
            len[depth] = nameLen;
        else
            len[depth] = len[depth - 1] + 1 + nameLen;

        if (isFile && len[depth] > maxLen)
            maxLen = len[depth];

        if (*p == '\n')
            p++;
    }

    return maxLen;
}