class Solution {

    function maximumSwap($num) {
        $s = str_split((string)$num);
        $last = array_fill(0, 10, -1);

        for ($i = 0; $i < count($s); $i++) {
            $last[(int)$s[$i]] = $i;
        }

        for ($i = 0; $i < count($s); $i++) {
            $current = (int)$s[$i];

            for ($digit = 9; $digit > $current; $digit--) {
                if ($last[$digit] > $i) {
                    $j = $last[$digit];

                    $temp = $s[$i];
                    $s[$i] = $s[$j];
                    $s[$j] = $temp;

                    return (int)implode('', $s);
                }
            }
        }

        return $num;
    }
}