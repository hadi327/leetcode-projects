
class Solution {
    public int countRatioSubarrays(int[] nums, int a, int b) {
        int n = nums.length;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int odd = 0;

            for (int j = i; j < n; j++) {
                if (nums[j] % 2 != 0) {
                    odd++;
                }

                int len = j - i + 1;
                int even = len - odd;

                if (odd > 0 && (long) even * b <= (long) odd * a) {
                    ans++;
                }
            }
        }

        return ans;
    }
}
