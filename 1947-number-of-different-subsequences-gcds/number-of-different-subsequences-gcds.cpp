class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<bool> present(mx + 1, false);

        for (int x : nums)
            present[x] = true;

        int ans = 0;

        for (int g = 1; g <= mx; g++) {
            int currentGCD = 0;

            // Look at all multiples of g
            for (int x = g; x <= mx; x += g) {
                if (present[x]) {
                    currentGCD = gcd(currentGCD, x);

                    if (currentGCD == g)
                        break;
                }
            }

            if (currentGCD == g)
                ans++;
        }

        return ans;
    }
};