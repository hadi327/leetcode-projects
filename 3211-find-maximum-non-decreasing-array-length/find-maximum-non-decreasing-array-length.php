class Solution {
    function findMaximumLength($nums) {
        $n = count($nums);

        $prefix = array_fill(0, $n + 1, 0);
        for ($i = 1; $i <= $n; $i++) {
            $prefix[$i] = $prefix[$i - 1] + $nums[$i - 1];
        }

        $dp = array_fill(0, $n + 1, 0);
        $pre = array_fill(0, $n + 2, 0);

        for ($i = 1; $i <= $n; $i++) {
            $pre[$i] = max($pre[$i], $pre[$i - 1]);

            $dp[$i] = $dp[$pre[$i]] + 1;

            // Find the first prefix sum >= 2 * prefix[i] - prefix[pre[i]]
            $target = 2 * $prefix[$i] - $prefix[$pre[$i]];

            $left = $i + 1;
            $right = $n + 1;

            while ($left < $right) {
                $mid = intdiv($left + $right, 2);

                if ($prefix[$mid] >= $target) {
                    $right = $mid;
                } else {
                    $left = $mid + 1;
                }
            }

            $pre[$left] = max($pre[$left], $i);
        }

        return $dp[$n];
    }
}