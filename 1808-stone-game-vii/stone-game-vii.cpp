class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();

        // Prefix sums
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stones[i];
        }

        // dp[l][r] = maximum score difference
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len <= n; l++) {
                int r = l + len - 1;

                int total = prefix[r + 1] - prefix[l];

                // Remove left stone
                int removeLeft =
                    (total - stones[l]) - dp[l + 1][r];

                // Remove right stone
                int removeRight =
                    (total - stones[r]) - dp[l][r - 1];

                dp[l][r] = max(removeLeft, removeRight);
            }
        }

        return dp[0][n - 1];
    }
};
