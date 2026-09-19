class Solution {

    function preimageSizeFZF($k) {
        $left = 0;
        $right = 5 * ($k + 1);

        while ($left <= $right) {
            $mid = intdiv($left + $right, 2);
            $zeros = $this->trailingZeroes($mid);

            if ($zeros == $k) {
                return 5;
            }

            if ($zeros < $k) {
                $left = $mid + 1;
            } else {
                $right = $mid - 1;
            }
        }

        return 0;
    }

    private function trailingZeroes($n) {
        $result = 0;

        while ($n > 0) {
            $n = intdiv($n, 5);
            $result += $n;
        }

        return $result;
    }
}