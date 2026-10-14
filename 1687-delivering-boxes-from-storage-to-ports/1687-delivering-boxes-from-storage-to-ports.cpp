class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        int n = boxes.size();
        vector<long long> prefix_sum(n + 1, 0);
        vector<int> count(n, 0);
        for (int i = 0; i < n; i++) prefix_sum[i + 1] = prefix_sum[i] + boxes[i][1];
        for (int i = 1; i < n; i++)
            count[i] = count[i - 1] + (boxes[i][0] != boxes[i - 1][0]);

        deque<int> dq;
        vector<int> dp(n + 1, 1e9);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {
            while (!dq.empty() && count[dq.back()] + dp[dq.back() + 1] >= count[i] + dp[i + 1])   
            dq.pop_back();
            dq.push_back(i);
            while (!dq.empty() && (prefix_sum[dq.front() + 1] - prefix_sum[i] > maxWeight ||
                    dq.front() - i + 1 > maxBoxes))
                dq.pop_front();
            dp[i] = dp[dq.front() + 1] + count[dq.front()] - count[i] + 2;
        }
        return dp[0];
    }
};