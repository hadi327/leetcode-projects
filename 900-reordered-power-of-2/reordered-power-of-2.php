class Solution {

    function reorderedPowerOf2($n) {
        $target = $this->countDigits($n);

        for ($i = 0; $i <= 30; $i++) {
            $power = 1 << $i;

            if ($this->countDigits($power) == $target) {
                return true;
            }
        }

        return false;
    }

    private function countDigits($n) {
        $count = array_fill(0, 10, 0);

        foreach (str_split((string)$n) as $digit) {
            $count[(int)$digit]++;
        }

        return implode(',', $count);
    }
}