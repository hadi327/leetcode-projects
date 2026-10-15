class Solution {
    function countNonDecreasingSubarrays($nums, $k) {
        $n = count($nums);
        $deque = [];
        $head = 0;
        $tail = 0;

        $right = $n - 1;
        $cost = 0;
        $ans = 0;

        for ($i = $n - 1; $i >= 0; $i--) {
            $num = $nums[$i];

            // Merge smaller values into the current value.
            while (
                $head < $tail &&
                $nums[$deque[$tail - 1]] < $num
            ) {
                $leftIndex = $deque[--$tail];

                $nextIndex = ($head < $tail)
                    ? $deque[$tail - 1]
                    : $right + 1;

                $cost += ($nextIndex - $leftIndex)
                       * ($num - $nums[$leftIndex]);
            }

            $deque[$tail++] = $i;

            // Shrink the window until the cost is within k.
            while ($cost > $k) {
                $cost -= $nums[$deque[$head]] - $nums[$right];

                if ($deque[$head] == $right) {
                    $head++;
                }

                $right--;
            }

            // Count valid subarrays starting at i.
            $ans += $right - $i + 1;
        }

        return $ans;
    }
}