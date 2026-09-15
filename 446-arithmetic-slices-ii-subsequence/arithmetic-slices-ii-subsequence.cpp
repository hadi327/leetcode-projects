class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();

        vector<unordered_map<long long, long long>> dp(n);
        long long result = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long diff =
                    (long long)nums[i] - nums[j];

                long long previous =
                    dp[j].count(diff)
                    ? dp[j][diff]
                    : 0;

                dp[i][diff] += previous + 1;
                result += previous;
            }
        }

        return (int)result;
    }
};