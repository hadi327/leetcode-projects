class Solution {
    public long minimumReplacement(int[] nums) {
        long operations = 0;
        long limit = nums[nums.length - 1];

        for (int i = nums.length - 2; i >= 0; i--) {
            long current = nums[i];

            if (current <= limit) {
                limit = current;
                continue;
            }

            long parts = (current + limit - 1) / limit;

            operations += parts - 1;

            limit = current / parts;
        }

        return operations;
    }
}