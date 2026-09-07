class Solution {
    function calculate($s) {
        $result = 0;
        $number = 0;
        $sign = 1;
        $stack = [];

        $n = strlen($s);

        for ($i = 0; $i < $n; $i++) {
            $ch = $s[$i];

            if (ctype_digit($ch)) {
                $number = $number * 10 + intval($ch);
            }
            elseif ($ch == '+') {
                $result += $sign * $number;
                $number = 0;
                $sign = 1;
            }
            elseif ($ch == '-') {
                $result += $sign * $number;
                $number = 0;
                $sign = -1;
            }
            elseif ($ch == '(') {
                $stack[] = $result;
                $stack[] = $sign;

                $result = 0;
                $sign = 1;
            }
            elseif ($ch == ')') {
                $result += $sign * $number;
                $number = 0;

                $prevSign = array_pop($stack);
                $prevResult = array_pop($stack);

                $result = $prevResult +
                          $prevSign * $result;
            }
        }

        return $result + $sign * $number;
    }
}