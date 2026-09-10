bool canConstruct(char* ransomNote, char* magazine) {
    int freq[26] = {0};

    for (int i = 0; magazine[i] != '\0'; i++) {
        freq[magazine[i] - 'a']++;
    }

    for (int i = 0; ransomNote[i] != '\0'; i++) {
        int index = ransomNote[i] - 'a';

        if (freq[index] == 0) {
            return false;
        }

        freq[index]--;
    }

    return true;
}