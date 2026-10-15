class Solution {
    function minimumCoins($prices) {
        $n = count($prices);
        $dp = array_fill(0, $n + 2, 0);

        for ($i = $n; $i >= 1; $i--) {
            $dp[$i] = PHP_INT_MAX;

            $last = min($n, 2 * $i);

            for ($j = $i + 1; $j <= $last + 1; $j++) {
                $dp[$i] = min(
                    $dp[$i],
                    $prices[$i - 1] + $dp[$j]
                );
            }
        }

        return $dp[1];
    }
}