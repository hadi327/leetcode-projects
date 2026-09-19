class Solution {

    function minSteps($n) {
        $result = 0;

        for ($factor = 2; $factor <= $n; $factor++) {
            while ($n % $factor == 0) {
                $result += $factor;
                $n /= $factor;
            }
        }

        return $result;
    }
}