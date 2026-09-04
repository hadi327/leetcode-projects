class Solution {
    public function firstStableIndex($nums, $k) {
        $n = count($nums);

        // Suffix minimum
        $suffixMin = array_fill(0, $n, 0);
        $suffixMin[$n - 1] = $nums[$n - 1];

        for ($i = $n - 2; $i >= 0; $i--) {
            $suffixMin[$i] = min($nums[$i], $suffixMin[$i + 1]);
        }

        // Prefix maximum
        $prefixMax = $nums[0];

        for ($i = 0; $i < $n; $i++) {
            $prefixMax = max($prefixMax, $nums[$i]);

            if ($prefixMax - $suffixMin[$i] <= $k) {
                return $i;
            }
        }

        return -1;
    }
}