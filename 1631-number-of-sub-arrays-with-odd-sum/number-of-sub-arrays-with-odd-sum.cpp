class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const long long MOD = 1e9 + 7;

        long long even = 1; // empty prefix
        long long odd = 0;
        long long ans = 0;

        int parity = 0;

        for (int x : arr) {
            parity ^= (x & 1);

            if (parity == 0) {
                // Current prefix is even.
                // Previous odd prefixes create odd-sum subarrays.
                ans = (ans + odd) % MOD;
                even++;
            } else {
                // Current prefix is odd.
                // Previous even prefixes create odd-sum subarrays.
                ans = (ans + even) % MOD;
                odd++;
            }
        }

        return ans;
    }
};