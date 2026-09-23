class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> perm(n);

        for (int i = 0; i < n; i++)
            perm[i] = i;

        vector<int> original = perm;
        int operations = 0;

        do {
            vector<int> next(n);

            for (int i = 0; i < n; i++) {
                if (i % 2 == 0)
                    next[i] = perm[i / 2];
                else
                    next[i] = perm[n / 2 + (i - 1) / 2];
            }

            perm = next;
            operations++;

        } while (perm != original);

        return operations;
    }
};