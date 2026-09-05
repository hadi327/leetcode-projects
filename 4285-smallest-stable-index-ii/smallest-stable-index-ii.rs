impl Solution {
    pub fn first_stable_index(nums: Vec<i32>, k: i32) -> i32 {
        let n = nums.len();

        let mut suffix_min = vec![0; n];
        suffix_min[n - 1] = nums[n - 1];

        // Build suffix minimum
        for i in (0..n - 1).rev() {
            suffix_min[i] = suffix_min[i + 1].min(nums[i]);
        }

        // Maintain prefix maximum
        let mut prefix_max = 0;

        for i in 0..n {
            prefix_max = prefix_max.max(nums[i]);

            if prefix_max - suffix_min[i] <= k {
                return i as i32;
            }
        }

        -1
    }
}