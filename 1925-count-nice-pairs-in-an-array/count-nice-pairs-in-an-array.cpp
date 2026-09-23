class Solution {
public:
    int reverseNum(int x) {
        int rev = 0;

        while (x > 0) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }

        return rev;
    }

    int countNicePairs(vector<int>& nums) {
        const long long MOD = 1e9 + 7;

        unordered_map<int, long long> freq;
        long long ans = 0;

        for (int x : nums) {
            int key = x - reverseNum(x);

            // Every previous number with the same key
            // forms a nice pair with x.
            ans = (ans + freq[key]) % MOD;

            freq[key]++;
        }

        return ans;
    }
};