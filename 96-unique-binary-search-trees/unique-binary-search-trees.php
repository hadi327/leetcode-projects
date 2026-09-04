class Solution {
    public function numTrees($n) {
        $dp = array_fill(0, $n + 1, 0);

        $dp[0] = 1;
        $dp[1] = 1;

        for ($nodes = 2; $nodes <= $n; $nodes++) {
            for ($root = 1; $root <= $nodes; $root++) {
                $dp[$nodes] +=
                    $dp[$root - 1] * $dp[$nodes - $root];
            }
        }

        return $dp[$n];
    }
}