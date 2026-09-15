class Solution {
public:
    int fourSumCount(
        vector<int>& nums1,
        vector<int>& nums2,
        vector<int>& nums3,
        vector<int>& nums4
    ) {
        unordered_map<int, int> count;

        for (int a : nums1) {
            for (int b : nums2) {
                count[a + b]++;
            }
        }

        int result = 0;

        for (int c : nums3) {
            for (int d : nums4) {
                int target = -(c + d);

                if (count.count(target)) {
                    result += count[target];
                }
            }
        }

        return result;
    }
};