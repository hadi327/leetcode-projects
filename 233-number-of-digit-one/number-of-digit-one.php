class Solution {
    function countDigitOne($n) {
        $count = 0;

        for ($factor = 1; $factor <= $n; $factor *= 10) {
            $higher = intdiv($n, $factor * 10);
            $current = intdiv($n, $factor) % 10;
            $lower = $n % $factor;

            if ($current == 0) {
                $count += $higher * $factor;
            }
            elseif ($current == 1) {
                $count += $higher * $factor +
                          $lower + 1;
            }
            else {
                $count += ($higher + 1) * $factor;
            }
        }

        return $count;
    }
}