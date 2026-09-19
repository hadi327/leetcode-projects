class Solution {

    function rotatedDigits($n) {
        $result = 0;

        for ($num = 1; $num <= $n; $num++) {
            $x = $num;
            $valid = true;
            $changed = false;

            while ($x > 0) {
                $digit = $x % 10;

                if ($digit == 2 ||
                    $digit == 5 ||
                    $digit == 6 ||
                    $digit == 9) {
                    $changed = true;
                }
                elseif ($digit == 0 ||
                        $digit == 1 ||
                        $digit == 8) {
                    // Valid unchanged digit.
                }
                else {
                    $valid = false;
                    break;
                }

                $x = intdiv($x, 10);
            }

            if ($valid && $changed) {
                $result++;
            }
        }

        return $result;
    }
}