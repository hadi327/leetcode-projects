class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int days = n % 7;

        // Sum of the first day of each complete week:
        // 1 + 2 + ... + weeks
        int ans = 28 * weeks + 7 * weeks * (weeks - 1) / 2;

        // Remaining days
        int start = weeks + 1;

        for (int i = 0; i < days; i++) {
            ans += start + i;
        }

        return ans;
    }
};