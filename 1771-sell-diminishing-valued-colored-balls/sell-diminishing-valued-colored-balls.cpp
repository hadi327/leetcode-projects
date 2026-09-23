class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        const long long MOD = 1e9 + 7;

        sort(inventory.rbegin(), inventory.rend());

        long long ans = 0;
        long long colors = 1;

        for (int i = 0; i < inventory.size(); i++) {
            long long current = inventory[i];
            long long next = (i + 1 < inventory.size())
                             ? inventory[i + 1]
                             : 0;

            long long count = (current - next) * colors;

            if (orders >= count) {
                // Sell everything from current down to next + 1
                long long sum = (current + next + 1) * (current - next) / 2;

                ans = (ans + (sum % MOD) * colors) % MOD;
                orders -= count;
            } else {
                // We only need part of this level
                long long fullLevels = orders / colors;
                long long remainder = orders % colors;

                long long low = current - fullLevels + 1;

                // Sell full levels
                long long sum =
                    (current + low) * fullLevels / 2;

                ans = (ans + sum * colors) % MOD;

                // Sell remaining balls at the next value
                ans = (ans + remainder * (current - fullLevels)) % MOD;

                break;
            }

            colors++;
        }

        return ans % MOD;
    }
};