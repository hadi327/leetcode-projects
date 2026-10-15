class Solution {
    function maxTaskAssign($tasks, $workers, $pills, $strength) {
        sort($tasks);
        sort($workers);

        $n = count($tasks);
        $m = count($workers);

        $left = 0;
        $right = min($n, $m);

        while ($left < $right) {
            $mid = intdiv($left + $right + 1, 2);

            if ($this->canAssign(
                $tasks, $workers, $pills, $strength, $mid
            )) {
                $left = $mid;
            } else {
                $right = $mid - 1;
            }
        }

        return $left;
    }

    private function canAssign(
        $tasks, $workers, $pills, $strength, $x
    ) {
        $n = count($tasks);
        $m = count($workers);

        $deque = [];
        $head = 0;
        $tail = 0;
        $taskIndex = 0;
        $remainingPills = $pills;

        // Use the x strongest workers, from weakest to strongest.
        for ($j = $m - $x; $j < $m; $j++) {
            while (
                $taskIndex < $x &&
                $tasks[$taskIndex] <= $workers[$j] + $strength
            ) {
                $deque[$tail++] = $tasks[$taskIndex++];
            }

            if ($head >= $tail) {
                return false;
            }

            // Complete the easiest available task without a pill.
            if ($deque[$head] <= $workers[$j]) {
                $head++;
            } else {
                // A pill is required: use it on the hardest
                // task this worker can complete.
                if ($remainingPills == 0) {
                    return false;
                }

                $remainingPills--;
                $tail--;
            }
        }

        return true;
    }
}