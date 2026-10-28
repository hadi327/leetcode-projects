class Solution {
    public function minCost($grid) {
        $m = count($grid);
        $n = count($grid[0]);
        $limit = 1024;

        $dp = array_fill(0, $n, array_fill(0, $limit, false));

        for ($i = 0; $i < $m; $i++) {
            for ($j = 0; $j < $n; $j++) {
                $value = $grid[$i][$j];
                $current = array_fill(0, $limit, false);

                if ($i == 0 && $j == 0) {
                    $current[$value] = true;
                } else {
                    if ($i > 0) {
                        for ($x = 0; $x < $limit; $x++) {
                            if ($dp[$j][$x]) {
                                $current[$x ^ $value] = true;
                            }
                        }
                    }

                    if ($j > 0) {
                        for ($x = 0; $x < $limit; $x++) {
                            if ($dp[$j - 1][$x]) {
                                $current[$x ^ $value] = true;
                            }
                        }
                    }
                }

                $dp[$j] = $current;
            }
        }

        for ($x = 0; $x < $limit; $x++) {
            if ($dp[$n - 1][$x]) {
                return $x;
            }
        }

        return 0;
    }
}