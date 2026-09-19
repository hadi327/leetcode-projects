class Solution {

    function judgePoint24($cards) {
        $nums = array_map('floatval', $cards);

        return $this->solve($nums);
    }

    private function solve($nums) {
        $n = count($nums);

        if ($n == 1) {
            return abs($nums[0] - 24.0) < 1e-6;
        }

        for ($i = 0; $i < $n; $i++) {
            for ($j = $i + 1; $j < $n; $j++) {

                $remaining = [];

                for ($k = 0; $k < $n; $k++) {
                    if ($k != $i && $k != $j) {
                        $remaining[] = $nums[$k];
                    }
                }

                $a = $nums[$i];
                $b = $nums[$j];

                $values = [
                    $a + $b,
                    $a - $b,
                    $b - $a,
                    $a * $b
                ];

                if (abs($b) > 1e-6) {
                    $values[] = $a / $b;
                }

                if (abs($a) > 1e-6) {
                    $values[] = $b / $a;
                }

                foreach ($values as $value) {
                    $remaining[] = $value;

                    if ($this->solve($remaining)) {
                        return true;
                    }

                    array_pop($remaining);
                }
            }
        }

        return false;
    }
}