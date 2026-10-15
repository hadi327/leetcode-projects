class Solution {
    function maximumRobots($chargeTimes, $runningCosts, $budget) {
        $n = count($chargeTimes);
        $deque = [];
        $head = 0;
        $tail = 0;

        $left = 0;
        $sumRunning = 0;
        $answer = 0;

        for ($right = 0; $right < $n; $right++) {
            $sumRunning += $runningCosts[$right];

            // Keep charge times in decreasing order.
            while (
                $head < $tail &&
                $chargeTimes[$deque[$tail - 1]] <= $chargeTimes[$right]
            ) {
                $tail--;
            }

            $deque[$tail++] = $right;

            // Shrink the window while it exceeds the budget.
            while (
                $head < $tail &&
                $chargeTimes[$deque[$head]]
                    + ($right - $left + 1) * $sumRunning > $budget
            ) {
                if ($deque[$head] == $left) {
                    $head++;
                }

                $sumRunning -= $runningCosts[$left];
                $left++;
            }

            $answer = max($answer, $right - $left + 1);
        }

        return $answer;
    }
}