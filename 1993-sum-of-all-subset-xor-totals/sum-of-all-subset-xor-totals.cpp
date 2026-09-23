class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int totalOR = 0;

        for (int x : nums)
            totalOR |= x;

        return totalOR << (nums.size() - 1);
    }
};