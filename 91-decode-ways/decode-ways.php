class Solution {
    public function numDecodings($s) {
        $n = strlen($s);

        if ($n == 0 || $s[0] == '0') {
            return 0;
        }

        $dp = array_fill(0, $n + 1, 0);
        $dp[0] = 1;
        $dp[1] = 1;

        for ($i = 2; $i <= $n; $i++) {
            if ($s[$i - 1] != '0') {
                $dp[$i] += $dp[$i - 1];
            }

            $two = intval(substr($s, $i - 2, 2));

            if ($two >= 10 && $two <= 26) {
                $dp[$i] += $dp[$i - 2];
            }
        }

        return $dp[$n];
    }
}