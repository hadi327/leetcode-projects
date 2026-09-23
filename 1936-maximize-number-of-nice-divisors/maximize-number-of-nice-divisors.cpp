class Solution {
public:
    static const long long MOD = 1000000007;

    long long modPow(long long base, long long exp) {
        long long result = 1;

        while (exp > 0) {
            if (exp & 1)
                result = result * base % MOD;

            base = base * base % MOD;
            exp >>= 1;
        }

        return result;
    }

    int maxNiceDivisors(int primeFactors) {
        if (primeFactors <= 3)
            return primeFactors;

        int rem = primeFactors % 3;

        if (rem == 0) {
            return modPow(3, primeFactors / 3);
        }

        if (rem == 1) {
            return modPow(3, (primeFactors - 4) / 3) * 4 % MOD;
        }

        return modPow(3, primeFactors / 3) * 2 % MOD;
    }
};