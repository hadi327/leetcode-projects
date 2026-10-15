class Solution {
    function countPartitions($nums, $k) {
        $n = count($nums);
        $MOD = 1000000007;

        $dp = array_fill(0, $n + 1, 0);
        $prefix = array_fill(0, $n + 2, 0);

        $dp[0] = 1;
        $prefix[1] = 1;

        $left = 0;
        $maxDeque = [];
        $minDeque = [];
        $maxHead = $maxTail = 0;
        $minHead = $minTail = 0;

        for ($right = 0; $right < $n; $right++) {
            // Maintain decreasing deque for maximum.
            while (
                $maxHead < $maxTail &&
                $nums[$maxDeque[$maxTail - 1]] <= $nums[$right]
            ) {
                $maxTail--;
            }
            $maxDeque[$maxTail++] = $right;

            // Maintain increasing deque for minimum.
            while (
                $minHead < $minTail &&
                $nums[$minDeque[$minTail - 1]] >= $nums[$right]
            ) {
                $minTail--;
            }
            $minDeque[$minTail++] = $right;

            // Find the smallest valid window.
            while (
                $nums[$maxDeque[$maxHead]] -
                $nums[$minDeque[$minHead]] > $k
            ) {
                if ($maxDeque[$maxHead] == $left) {
                    $maxHead++;
                }
                if ($minDeque[$minHead] == $left) {
                    $minHead++;
                }
                $left++;
            }

            // Count partitions ending at right.
            $dp[$right + 1] = (
                $prefix[$right + 1] - $prefix[$left] + $MOD
            ) % $MOD;

            $prefix[$right + 2] = (
                $prefix[$right + 1] + $dp[$right + 1]
            ) % $MOD;
        }

        return $dp[$n];
    }
}