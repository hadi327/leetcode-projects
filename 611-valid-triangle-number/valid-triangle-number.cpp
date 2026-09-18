class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int result = 0;

        for (int k = n - 1; k >= 2; k--) {
            int left = 0;
            int right = k - 1;

            while (left < right) {
                if (nums[left] + nums[right] > nums[k]) {
                    // Every index from left to right-1 works
                    result += right - left;
                    right--;
                } else {
                    left++;
                }
            }
        }

        return result;
    }
};