class Solution {
    public function grayCode($n) {
        $result = [0];

        for ($i = 0; $i < $n; $i++) {
            $size = count($result);

            for ($j = $size - 1; $j >= 0; $j--) {
                $result[] = $result[$j] | (1 << $i);
            }
        }

        return $result;
    }
}