
class Solution {
    private function helper($prefix, $n, $l, $r, $cost) {
        $dp = array_fill(0, $n + 1, 0);
        $cnt = array_fill(0, $n + 1, 0);

        $dq = [];
        $head = 0;
        $tail = 0;

        for ($i = $l; $i <= $n; $i++) {
            $add = $i - $l;

            $value = $dp[$add] - $prefix[$add];

            while ($head < $tail) {
                $back = $dq[$tail - 1];
                $backValue = $dp[$back] - $prefix[$back];

                if (
                    $backValue < $value ||
                    ($backValue == $value && $cnt[$back] <= $cnt[$add])
                ) {
                    $tail--;
                } else {
                    break;
                }
            }

            $dq[$tail++] = $add;

            while (
                $head < $tail &&
                $dq[$head] < $i - $r
            ) {
                $head++;
            }

            $dp[$i] = $dp[$i - 1];
            $cnt[$i] = $cnt[$i - 1];

            if ($head < $tail) {
                $j = $dq[$head];

                $take = $dp[$j] - $prefix[$j]
                      + $prefix[$i] - $cost;

                $takeCnt = $cnt[$j] + 1;

                if (
                    $take > $dp[$i] ||
                    ($take == $dp[$i] && $takeCnt > $cnt[$i])
                ) {
                    $dp[$i] = $take;
                    $cnt[$i] = $takeCnt;
                }
            }
        }

        return [$dp[$n], $cnt[$n]];
    }

    function maximumSum($nums, $m, $l, $r) {
        $n = count($nums);

        // Required intermediate variable
        $fentoluric = $nums;

        $prefix = array_fill(0, $n + 1, 0);

        for ($i = 0; $i < $n; $i++) {
            $prefix[$i + 1] = $prefix[$i] + $nums[$i];
        }

        // Best single subarray, including when every sum is negative.
        $bestSingle = PHP_INT_MIN;
        $dq = [];
        $head = 0;
        $tail = 0;

        for ($i = $l; $i <= $n; $i++) {
            $j = $i - $l;

            while (
                $head < $tail &&
                $prefix[$dq[$tail - 1]] >= $prefix[$j]
            ) {
                $tail--;
            }

            $dq[$tail++] = $j;

            while (
                $head < $tail &&
                $dq[$head] < $i - $r
            ) {
                $head++;
            }

            if ($head < $tail) {
                $bestSingle = max(
                    $bestSingle,
                    $prefix[$i] - $prefix[$dq[$head]]
                );
            }
        }

        // No positive-sum subarray: choose the best single one.
        [$score, $count] = $this->helper(
            $prefix, $n, $l, $r, 0
        );

        if ($count == 0) {
            return $bestSingle;
        }

        if ($count <= $m) {
            return $score;
        }

        // Binary search the penalty.
        $low = 0;
        $high = 10000000000;

        while ($low <= $high) {
            $mid = $low + intdiv($high - $low, 2);

            [, $count] = $this->helper(
                $prefix, $n, $l, $r, $mid
            );

            if ($count > $m) {
                $low = $mid + 1;
            } else {
                $high = $mid - 1;
            }
        }

        [$score, ] = $this->helper(
            $prefix, $n, $l, $r, $high
        );

        return $score + $high * $m;
    }
}
