class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int jumboNumerator = tomatoSlices - 2 * cheeseSlices;

        // Jumbo count must be non-negative and even
        if (jumboNumerator < 0 || jumboNumerator % 2 != 0)
            return {};

        int jumbo = jumboNumerator / 2;
        int small = cheeseSlices - jumbo;

        if (small < 0)
            return {};

        return {jumbo, small};
    }
};