class Solution {

    public function minOperations($nums) {
        $n = count($nums);
        $zero = array_search(0, $nums);

        $check = function($step) use ($nums, $n, $zero) {
            for ($i = 1; $i < $n; $i++) {
                $prev = (($zero + ($i - 1) * $step) % $n + $n) % $n;
                $curr = (($zero + $i * $step) % $n + $n) % $n;

                if ($nums[$prev] > $nums[$curr]) {
                    return false;
                }
            }

            return true;
        };

        $ans = PHP_INT_MAX;

        if ($check(1)) {
            $ans = min($ans, $zero);
            $ans = min($ans, $n - $zero + 2);
        }

        if ($check(-1)) {
            $ans = min($ans, $zero + 2);
            $ans = min($ans, $n - $zero);
        }

        return $ans === PHP_INT_MAX ? -1 : $ans;
    }
}