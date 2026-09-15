class Solution {
public:
    int magicalString(int n) {
        if (n <= 0)
            return 0;

        if (n <= 3)
            return 1;

        vector<int> s(n + 2);
        s[0] = 1;
        s[1] = 2;
        s[2] = 2;

        int read = 2;
        int write = 3;
        int number = 1;
        int countOnes = 1;

        while (write < n) {
            int times = s[read++];

            for (int i = 0; i < times && write < n; i++) {
                s[write++] = number;

                if (number == 1)
                    countOnes++;
            }

            number = 3 - number;
        }

        return countOnes;
    }
};