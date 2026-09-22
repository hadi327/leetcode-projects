class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int g = 0;

        for (int num : nums) {
            g = gcd(g, num);

            if (g == 1)
                return true;
        }

        return false;
    }
};