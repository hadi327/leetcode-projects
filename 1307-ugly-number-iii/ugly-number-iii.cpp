class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    int nthUglyNumber(int n, int a, int b, int c) {
        long long ab = lcm(a, b);
        long long ac = lcm(a, c);
        long long bc = lcm(b, c);

        long long abc = lcm(ab, c);

        auto count = [&](long long x) {
            return x / a
                 + x / b
                 + x / c
                 - x / ab
                 - x / ac
                 - x / bc
                 + x / abc;
        };

        long long left = 1;
        long long right = 2LL * 1e9;

        while (left < right) {
            long long mid = left + (right - left) / 2;

            if (count(mid) >= n) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};