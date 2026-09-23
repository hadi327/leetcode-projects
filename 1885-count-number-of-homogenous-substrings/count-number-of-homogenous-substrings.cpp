class Solution {
public:
    int countHomogenous(string s) {
        const long long MOD = 1e9 + 7;

        long long ans = 0;
        long long streak = 0;
        char prev = '#';

        for (char c : s) {
            if (c == prev)
                streak++;
            else
                streak = 1;

            ans = (ans + streak) % MOD;
            prev = c;
        }

        return ans;
    }
};