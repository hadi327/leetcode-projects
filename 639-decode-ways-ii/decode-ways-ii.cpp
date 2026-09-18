class Solution {
public:
    int numDecodings(string s) {
        const long long MOD = 1000000007;

        long long prev2 = 1;
        long long prev1 = waysOne(s[0]);

        for (int i = 1; i < s.size(); i++) {
            long long current = 0;

            current +=
                prev1 * waysOne(s[i]);

            current +=
                prev2 * waysTwo(s[i - 1], s[i]);

            current %= MOD;

            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }

private:
    long long waysOne(char c) {
        if (c == '*')
            return 9;

        if (c == '0')
            return 0;

        return 1;
    }

    long long waysTwo(char a, char b) {
        if (a == '*' && b == '*')
            return 15;

        if (a == '*') {
            if (b >= '0' && b <= '6')
                return 2;

            return 1;
        }

        if (b == '*') {
            if (a == '1')
                return 9;

            if (a == '2')
                return 6;

            return 0;
        }

        int value =
            (a - '0') * 10 + (b - '0');

        return value >= 10 && value <= 26 ? 1 : 0;
    }
};