class Solution {
    function maxResult($nums, $k) {
        $n = count($nums);
        $dp = array_fill(0, $n, 0);

        // Store indices in decreasing order of dp values
        $dq = [];
        $head = 0;
        $tail = 0;

        $dp[0] = $nums[0];
        $dq[$tail++] = 0;

        for ($i = 1; $i < $n; $i++) {
            // Remove indices outside the jump range
            while ($head < $tail && $dq[$head] < $i - $k) {
                $head++;
            }

            // Best score reaching index i
            $dp[$i] = $nums[$i] + $dp[$dq[$head]];

            // Maintain decreasing DP values
            while ($head < $tail &&
                   $dp[$dq[$tail - 1]] <= $dp[$i]) {
                $tail--;
            }

            $dq[$tail++] = $i;
        }

        return $dp[$n - 1];
    }
}