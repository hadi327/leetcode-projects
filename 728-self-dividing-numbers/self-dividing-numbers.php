class Solution {

    function selfDividingNumbers($left, $right) {
        $result = [];

        for ($num = $left; $num <= $right; $num++) {
            $x = $num;
            $valid = true;

            while ($x > 0) {
                $digit = $x % 10;

                if ($digit == 0 || $num % $digit != 0) {
                    $valid = false;
                    break;
                }

                $x = intdiv($x, 10);
            }

            if ($valid) {
                $result[] = $num;
            }
        }

        return $result;
    }
}