class Solution {

    function splitArraySameAverage($nums) {
        $n = count($nums);
        $sum = array_sum($nums);

        $dp = array_fill(
            0,
            intdiv($n, 2) + 1,
            []
        );

        $dp[0][0] = true;

        for ($i = 0; $i < $n; $i++) {
            for ($count = intdiv($n, 2); $count >= 1; $count--) {
                foreach ($dp[$count - 1] as $value => $_) {
                    $newSum = $value + $nums[$i];
                    $dp[$count][$newSum] = true;
                }
            }
        }

        for ($count = 1; $count <= intdiv($n, 2); $count++) {
            if (($sum * $count) % $n != 0) {
                continue;
            }

            $target = intdiv($sum * $count, $n);

            if (isset($dp[$count][$target])) {
                return true;
            }
        }

        return false;
    }
}