class Solution {
public:
    unordered_map<int, bool> memo;

    bool dfs(int used, int current, int maxChoosable, int target) {
        if (current >= target)
            return false;

        if (memo.count(used))
            return memo[used];

        for (int i = 1; i <= maxChoosable; i++) {
            int bit = 1 << (i - 1);

            if (used & bit)
                continue;

            if (!dfs(used | bit, current + i,
                     maxChoosable, target)) {
                return memo[used] = true;
            }
        }

        return memo[used] = false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = maxChoosableInteger *
                  (maxChoosableInteger + 1) / 2;

        if (sum < desiredTotal)
            return false;

        if (desiredTotal <= 0)
            return true;

        memo.clear();

        return dfs(0, 0, maxChoosableInteger, desiredTotal);
    }
};