#include <stdbool.h>

bool isPalindrome(char* s) {
    int left = 0;
    int right = 0;

    while (s[right] != '\0')
        right++;

    right--;

    while (left < right) {
        while (left < right &&
               !((s[left] >= 'a' && s[left] <= 'z') ||
                 (s[left] >= 'A' && s[left] <= 'Z') ||
                 (s[left] >= '0' && s[left] <= '9'))) {
            left++;
        }

        while (left < right &&
               !((s[right] >= 'a' && s[right] <= 'z') ||
                 (s[right] >= 'A' && s[right] <= 'Z') ||
                 (s[right] >= '0' && s[right] <= '9'))) {
            right--;
        }

        char a = s[left];
        char b = s[right];

        if (a >= 'A' && a <= 'Z')
            a += 'a' - 'A';

        if (b >= 'A' && b <= 'Z')
            b += 'a' - 'A';

        if (a != b)
            return false;

        left++;
        right--;
    }

    return true;
}