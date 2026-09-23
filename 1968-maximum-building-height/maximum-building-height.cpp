class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});

        sort(restrictions.begin(), restrictions.end());

        int m = restrictions.size();

        // Left to right
        for (int i = 1; i < m; i++) {
            int dist = restrictions[i][0] - restrictions[i - 1][0];

            restrictions[i][1] =
                min(restrictions[i][1],
                    restrictions[i - 1][1] + dist);
        }

        // Right to left
        for (int i = m - 2; i >= 0; i--) {
            int dist = restrictions[i + 1][0] - restrictions[i][0];

            restrictions[i][1] =
                min(restrictions[i][1],
                    restrictions[i + 1][1] + dist);
        }

        int ans = 0;

        // Check the maximum height between restrictions
        for (int i = 1; i < m; i++) {
            long long x1 = restrictions[i - 1][0];
            long long h1 = restrictions[i - 1][1];

            long long x2 = restrictions[i][0];
            long long h2 = restrictions[i][1];

            long long dist = x2 - x1;

            long long peak =
                (h1 + h2 + dist) / 2;

            ans = max(ans, (int)peak);
        }

        // After the last restriction, height can keep increasing by 1
        long long lastPos = restrictions.back()[0];
        long long lastHeight = restrictions.back()[1];

        ans = max(ans, (int)(lastHeight + n - lastPos));

        return ans;
    }
};