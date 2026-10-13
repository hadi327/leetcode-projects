
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> squares(n);

        for (int i = 0; i < n; i++) {
            squares[i] = 1LL * nums[i] * nums[i];
        }

        sort(squares.begin(), squares.end());

        long long ans = 0;

        // Subtract the smaller half
        for (int i = 0; i < n / 2; i++) {
            ans -= squares[i];
        }

        // Add the larger half
        for (int i = n / 2; i < n; i++) {
            ans += squares[i];
        }

        return ans;
    }
};
