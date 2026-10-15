class Solution {
    function maximumSum($nums, $m, $l, $r) {
        $n = count($nums);

        // Required variable
        $qerunavilo = $nums;

        $prefix = array_fill(0, $n + 1, 0);
        for ($i = 0; $i < $n; $i++) {
            $prefix[$i + 1] = $prefix[$i] + $nums[$i];
        }

        $NEG = -PHP_INT_MAX;
        $prev = array_fill(0, $n + 1, 0);
        $answer = $NEG;

        for ($c = 1; $c <= $m; $c++) {
            $curr = array_fill(0, $n + 1, $NEG);
            $deque = [];
            $head = 0;
            $tail = 0;

            for ($i = 1; $i <= $n; $i++) {
                // Option 1: skip the current element.
                $curr[$i] = $curr[$i - 1];

                // Add the valid starting index i - l.
                $j = $i - $l;

                if ($j >= 0 && $prev[$j] > $NEG) {
                    $value = $prev[$j] - $prefix[$j];

                    while (
                        $head < $tail &&
                        $prev[$deque[$tail - 1]]
                            - $prefix[$deque[$tail - 1]] <= $value
                    ) {
                        $tail--;
                    }

                    $deque[$tail++] = $j;
                }

                // Remove starting indices that exceed length r.
                while (
                    $head < $tail &&
                    $deque[$head] < $i - $r
                ) {
                    $head++;
                }

                // Option 2: select a subarray ending at i.
                if ($head < $tail) {
                    $j = $deque[$head];

                    $curr[$i] = max(
                        $curr[$i],
                        $prev[$j] + $prefix[$i] - $prefix[$j]
                    );
                }
            }

            $answer = max($answer, $curr[$n]);
            $prev = $curr;
        }

        return $answer;
    }
}