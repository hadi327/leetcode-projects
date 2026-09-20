class Solution {

    function consecutiveNumbersSum($n) {
        $result = 0;

        for ($k = 1; $k * ($k + 1) / 2 <= $n; $k++) {
            $remaining = $n - intdiv($k * ($k - 1), 2);

            if ($remaining % $k == 0) {
                $result++;
            }
        }

        return $result;
    }
}