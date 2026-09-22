class Solution {
public:
    int numPrimeArrangements(int n) {
        const long long MOD = 1e9 + 7;

        int primeCount = 0;

        for (int i = 2; i <= n; i++) {
            bool isPrime = true;

            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }

            if (isPrime) {
                primeCount++;
            }
        }

        long long primeWays = 1;
        long long nonPrimeWays = 1;

        for (int i = 1; i <= primeCount; i++) {
            primeWays = (primeWays * i) % MOD;
        }

        for (int i = 1; i <= n - primeCount; i++) {
            nonPrimeWays = (nonPrimeWays * i) % MOD;
        }

        return (primeWays * nonPrimeWays) % MOD;
    }
};