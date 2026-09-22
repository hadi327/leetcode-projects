class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for (int n : nums) {
            int count = 0;
            int sum = 0;

            for (int i = 1; i * i <= n; i++) {
                if (n % i == 0) {
                    int j = n / i;

                    count++;
                    sum += i;

                    if (i != j) {
                        count++;
                        sum += j;
                    }

                    // More than 4 divisors → impossible to use this number
                    if (count > 4)
                        break;
                }
            }

            if (count == 4)
                ans += sum;
        }

        return ans;
    }
};