class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();

        unordered_map<int, unordered_set<int>> dp;

        for (int stone : stones) {
            dp[stone] = {};
        }

        dp[0].insert(0);

        for (int stone : stones) {
            for (int jump : dp[stone]) {
                for (int next = jump - 1; next <= jump + 1; next++) {
                    if (next <= 0) continue;

                    int position = stone + next;

                    if (position == stones.back()) {
                        return true;
                    }

                    if (dp.count(position)) {
                        dp[position].insert(next);
                    }
                }
            }
        }

        return stones.size() == 1;
    }
};