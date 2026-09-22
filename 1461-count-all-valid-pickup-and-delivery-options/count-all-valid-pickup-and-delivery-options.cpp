class Solution {
public:
    int countOrders(int n) {
        const long long MOD = 1e9 + 7;
        long long ans = 1;

        for (int i = 1; i <= n; i++) {
            ans = ans * i % MOD;
            ans = ans * (2 * i - 1) % MOD;
        }

        return ans;
    }
};