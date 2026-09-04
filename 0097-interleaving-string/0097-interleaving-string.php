class Solution {
    public function isInterleave($s1, $s2, $s3) {
        $m = strlen($s1);
        $n = strlen($s2);

        if ($m + $n != strlen($s3)) {
            return false;
        }

        $dp = array_fill(0, $n + 1, false);
        $dp[0] = true;

        for ($j = 1; $j <= $n; $j++) {
            $dp[$j] = $dp[$j - 1] &&
                      $s2[$j - 1] == $s3[$j - 1];
        }

        for ($i = 1; $i <= $m; $i++) {
            $dp[0] = $dp[0] &&
                     $s1[$i - 1] == $s3[$i - 1];

            for ($j = 1; $j <= $n; $j++) {
                $k = $i + $j - 1;

                $dp[$j] =
                    ($dp[$j] && $s1[$i - 1] == $s3[$k]) ||
                    ($dp[$j - 1] && $s2[$j - 1] == $s3[$k]);
            }
        }

        return $dp[$n];
    }
}