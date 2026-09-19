class Solution {

    function findKthNumber($m, $n, $k) {
        $left = 1;
        $right = $m * $n;

        while ($left < $right) {
            $mid = intdiv($left + $right, 2);

            $count = 0;

            for ($i = 1; $i <= $m; $i++) {
                $count += min($n, intdiv($mid, $i));
            }

            if ($count >= $k) {
                $right = $mid;
            } else {
                $left = $mid + 1;
            }
        }

        return $left;
    }
}