class Solution {
    function continuousSubarrays($nums) {
        $n = count($nums);
        $minDeque = [];
        $maxDeque = [];
        $minHead = $minTail = 0;
        $maxHead = $maxTail = 0;

        $left = 0;
        $ans = 0;

        for ($right = 0; $right < $n; $right++) {
            while (
                $minHead < $minTail &&
                $nums[$minDeque[$minTail - 1]] >= $nums[$right]
            ) {
                $minTail--;
            }
            $minDeque[$minTail++] = $right;

            while (
                $maxHead < $maxTail &&
                $nums[$maxDeque[$maxTail - 1]] <= $nums[$right]
            ) {
                $maxTail--;
            }
            $maxDeque[$maxTail++] = $right;

            while (
                $nums[$maxDeque[$maxHead]] -
                $nums[$minDeque[$minHead]] > 2
            ) {
                if ($minDeque[$minHead] == $left) {
                    $minHead++;
                }
                if ($maxDeque[$maxHead] == $left) {
                    $maxHead++;
                }
                $left++;
            }

            $ans += $right - $left + 1;
        }

        return $ans;
    }
}