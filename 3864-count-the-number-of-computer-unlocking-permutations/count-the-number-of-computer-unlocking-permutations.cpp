
class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        const long long MOD = 1'000'000'007;
        int n = complexity.size();

        // Every other computer must be harder to unlock
        // than computer 0.
        for (int i = 1; i < n; i++) {
            if (complexity[i] <= complexity[0]) {
                return 0;
            }
        }

        // Computer 0 is already unlocked.
        // The remaining n - 1 computers can be unlocked
        // in any order.
        long long ans = 1;

        for (int i = 1; i < n; i++) {
            ans = (ans * i) % MOD;
        }

        return (int)ans;
    }
};
