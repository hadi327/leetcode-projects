class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        deque<int> dq;
        int ans = INT_MIN;

        for (int i = 0; i < n; i++) {
            while (!dq.empty() && dq.front() < i - k) {
                dq.pop_front();
            }

            dp[i] = nums[i];

            if (!dq.empty()) {
                dp[i] = max(dp[i], nums[i] + dp[dq.front()]);
            }

            ans = max(ans, dp[i]);

            while (!dq.empty() && dp[dq.back()] <= dp[i]) {
                dq.pop_back();
            }

            if (dp[i] > 0) {
                dq.push_back(i);
            }
        }

        return ans;
    }
};