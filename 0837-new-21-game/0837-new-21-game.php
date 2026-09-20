class Solution {

    function new21Game($n, $k, $maxPts) {
        if ($k == 0 || $n >= $k + $maxPts - 1) {
            return 1.0;
        }

        $dp = array_fill(0, $n + 1, 0.0);
        $dp[0] = 1.0;

        $window = 1.0;
        $result = 0.0;

        for ($i = 1; $i <= $n; $i++) {
            $dp[$i] = $window / $maxPts;

            if ($i < $k) {
                $window += $dp[$i];
            } else {
                $result += $dp[$i];
            }

            if ($i - $maxPts >= 0) {
                $window -= $dp[$i - $maxPts];
            }
        }

        return $result;
    }
}