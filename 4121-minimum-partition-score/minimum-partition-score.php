class Solution {
    function minPartitionScore($nums, $k) {
        $n = count($nums);

        $prefix = array_fill(0, $n + 1, 0);
        for ($i = 0; $i < $n; $i++) {
            $prefix[$i + 1] = $prefix[$i] + $nums[$i];
        }

        $INF = PHP_INT_MAX >> 2;
        $prev = array_fill(0, $n + 1, $INF);
        $prev[0] = 0;

        for ($t = 1; $t <= $k; $t++) {
            $curr = array_fill(0, $n + 1, $INF);
            $hull = [];

            for ($i = $t; $i <= $n - ($k - $t); $i++) {
                $j = $i - 1;

                if ($prev[$j] < $INF) {
                    $m = -$prefix[$j];
                    $b = $prev[$j]
                       + intdiv($prefix[$j] * ($prefix[$j] - 1), 2);

                    while (count($hull) >= 2) {
                        $a = $hull[count($hull) - 2];
                        $c = $hull[count($hull) - 1];

                        if (
                            ($c[1] - $a[1]) * ($a[0] - $m) >=
                            ($b - $a[1]) * ($a[0] - $c[0])
                        ) {
                            array_pop($hull);
                        } else {
                            break;
                        }
                    }

                    $hull[] = [$m, $b];
                }

                $x = $prefix[$i];

                while (
                    count($hull) >= 2 &&
                    $hull[0][0] * $x + $hull[0][1] >=
                    $hull[1][0] * $x + $hull[1][1]
                ) {
                    array_shift($hull);
                }

                if (!empty($hull)) {
                    $curr[$i] =
                        intdiv($x * ($x + 1), 2)
                        + $hull[0][0] * $x
                        + $hull[0][1];
                }
            }

            $prev = $curr;
        }

        return $prev[$n];
    }
}