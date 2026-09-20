class Solution {

    function reverseDegree($s) {
        $result = 0;

        for ($i = 0; $i < strlen($s); $i++) {
            $value = ord($s[$i]) - ord('a') + 1;
            $reverseValue = 27 - $value;

            $result += $reverseValue * ($i + 1);
        }

        return $result;
    }
}