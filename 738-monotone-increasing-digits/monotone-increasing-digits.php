class Solution {

    function monotoneIncreasingDigits($n) {
        $digits = str_split((string)$n);
        $mark = count($digits);

        for ($i = count($digits) - 1; $i > 0; $i--) {
            if ($digits[$i] < $digits[$i - 1]) {
                $digits[$i - 1]--;
                $mark = $i;
            }
        }

        for ($i = $mark; $i < count($digits); $i++) {
            $digits[$i] = '9';
        }

        return intval(implode('', $digits));
    }
}