class Solution {
public:
    static const long long MOD = 1e9 + 7;

    long long modPow(long long a, long long b) {
        long long res = 1;

        while (b > 0) {
            if (b & 1)
                res = res * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }

        return res;
    }

    long long comb(long long n, long long r) {
        if (r > n - r)
            r = n - r;

        long long numerator = 1;
        long long denominator = 1;

        for (long long i = 1; i <= r; i++) {
            numerator = numerator * ((n - r + i) % MOD) % MOD;
            denominator = denominator * i % MOD;
        }

        return numerator * modPow(denominator, MOD - 2) % MOD;
    }

    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        vector<int> ans;

        for (auto &q : queries) {
            int n = q[0];
            int k = q[1];

            long long ways = 1;
            int x = k;

            for (int p = 2; 1LL * p * p <= x; p++) {
                if (x % p == 0) {
                    int exponent = 0;

                    while (x % p == 0) {
                        x /= p;
                        exponent++;
                    }

                    ways = ways * comb(n + exponent - 1, exponent);
                    ways %= MOD;
                }
            }

            // Remaining prime factor
            if (x > 1) {
                ways = ways * n % MOD;
            }

            ans.push_back(ways);
        }

        return ans;
    }
};