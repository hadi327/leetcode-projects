class Solution {
public:
    int strongPasswordChecker(string password) {
        int n = password.size();

        bool lower = false;
        bool upper = false;
        bool digit = false;

        for (char c : password) {
            if (islower(c)) lower = true;
            if (isupper(c)) upper = true;
            if (isdigit(c)) digit = true;
        }

        int missing =
            (!lower) + (!upper) + (!digit);

        vector<int> runs;

        for (int i = 0; i < n;) {
            int j = i;

            while (j < n && password[j] == password[i]) {
                j++;
            }

            if (j - i >= 3) {
                runs.push_back(j - i);
            }

            i = j;
        }

        if (n < 6) {
            return max(missing, 6 - n);
        }

        int replacements = 0;

        for (int len : runs) {
            replacements += len / 3;
        }

        if (n <= 20) {
            return max(missing, replacements);
        }

        int deletions = n - 20;
        int remainingDeletions = deletions;

        // Remove characters from runs where len % 3 == 0.
        for (int& len : runs) {
            if (remainingDeletions == 0) break;

            if (len % 3 == 0) {
                int remove = min(1, remainingDeletions);
                len -= remove;
                remainingDeletions -= remove;
                replacements--;
            }
        }

        // Then handle runs where len % 3 == 1.
        for (int& len : runs) {
            if (remainingDeletions < 2) break;

            if (len % 3 == 1) {
                int remove = min(2, remainingDeletions);
                len -= remove;
                remainingDeletions -= remove;
                replacements -= remove / 2;
            }
        }

        // Every 3 deletions reduce one replacement.
        replacements -= remainingDeletions / 3;

        replacements = max(0, replacements);

        return deletions + max(missing, replacements);
    }
};