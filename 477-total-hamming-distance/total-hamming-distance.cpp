class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int result = 0;
        int n = nums.size();

        for (int bit = 0; bit < 31; bit++) {
            int ones = 0;

            for (int num : nums)
                if (num & (1 << bit))
                    ones++;

            result += ones * (n - ones);
        }

        return result;
    }
};