class Solution {
public:
    int kInversePairs(int n, int k) {
        const int MOD = 1e9 + 7;

        vector<int> dp(k + 1, 0);
        dp[0] = 1;

        for (int num = 1; num <= n; num++) {
            vector<int> next(k + 1, 0);

            long long window = 0;

            for (int j = 0; j <= k; j++) {
                window += dp[j];

                if (j >= num)
                    window -= dp[j - num];

                window %= MOD;

                if (window < 0)
                    window += MOD;

                next[j] = window;
            }

            dp = next;
        }

        return dp[k];
    }
};