class Solution {
    public function isFascinating($n) {
        $s = (string)$n . (string)($n * 2) . (string)($n * 3);

        if (strlen($s) != 9) {
            return false;
        }

        $digits = str_split($s);
        sort($digits);

        return implode('', $digits) === '123456789';
    }
}