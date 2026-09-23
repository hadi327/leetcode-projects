class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(), houses.end());

        int n = houses.size();

        // cost[i][j] = cost of serving houses i...j
        // with one mailbox
        vector<vector<int>> cost(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int mid = (i + j) / 2;

                for (int p = i; p <= j; p++) {
                    cost[i][j] += abs(houses[p] - houses[mid]);
                }
            }
        }

        const int INF = 1e9;

        vector<vector<int>> dp(
            n + 1,
            vector<int>(k + 1, INF)
        );

        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int boxes = 1; boxes <= k; boxes++) {

                for (int start = 0; start < i; start++) {
                    if (dp[start][boxes - 1] == INF)
                        continue;

                    dp[i][boxes] = min(
                        dp[i][boxes],
                        dp[start][boxes - 1] +
                        cost[start][i - 1]
                    );
                }
            }
        }

        return dp[n][k];
    }
};