int solve395(char* s, int left, int right, int k) {
    if (right - left < k)
        return 0;

    int freq[26] = {0};

    for (int i = left; i < right; i++)
        freq[s[i] - 'a']++;

    for (int i = left; i < right; i++) {

        if (freq[s[i] - 'a'] < k) {

            int j = i + 1;

            while (j < right &&
                   freq[s[j] - 'a'] < k) {
                j++;
            }

            int leftPart = solve395(s, left, i, k);
            int rightPart = solve395(s, j, right, k);

            return leftPart > rightPart ? leftPart : rightPart;
        }
    }

    return right - left;
}

int longestSubstring(char* s, int k) {
    return solve395(s, 0, strlen(s), k);
}