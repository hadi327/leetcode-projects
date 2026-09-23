class Fancy {
public:
    static const long long MOD = 1000000007;

    vector<long long> values;

    long long mul = 1;
    long long add = 0;

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

    long long inverse(long long x) {
        return modPow(x, MOD - 2);
    }

    Fancy() {}

    void append(int val) {
        // val = original * mul + add
        // original = (val - add) / mul

        long long original =
            (val - add + MOD) % MOD * inverse(mul) % MOD;

        values.push_back(original);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        mul = mul * m % MOD;
        add = add * m % MOD;
    }

    int getIndex(int idx) {
        if (idx >= values.size())
            return -1;

        return (values[idx] * mul + add) % MOD;
    }
};