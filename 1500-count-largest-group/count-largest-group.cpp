class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> freq(37, 0);

        for (int i = 1; i <= n; i++) {
            int x = i;
            int sum = 0;

            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }

            freq[sum]++;
        }

        int largest = 0;

        for (int x : freq)
            largest = max(largest, x);

        int ans = 0;

        for (int x : freq) {
            if (x == largest)
                ans++;
        }

        return ans;
    }
};