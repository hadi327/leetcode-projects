class Solution {
public:
    string smallestGoodBase(string n) {
        long long num = stoll(n);

        for (int m = 63; m >= 2; m--) {
            long long left = 2, right = pow(num, 1.0 / (m - 1)) + 2;

            while (left <= right) {
                long long k = left + (right - left) / 2;
                __int128 sum = 1;

                for (int i = 1; i < m; i++) {
                    sum = sum * k + 1;
                    if (sum > num) break;
                }

                if (sum == num)
                    return to_string(k);

                if (sum < num)
                    left = k + 1;
                else
                    right = k - 1;
            }
        }

        return to_string(num - 1);
    }
};