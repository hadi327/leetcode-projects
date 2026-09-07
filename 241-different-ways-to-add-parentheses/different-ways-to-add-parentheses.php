class Solution {
    private $memo = [];

    function diffWaysToCompute($expression) {
        if (isset($this->memo[$expression])) {
            return $this->memo[$expression];
        }

        $result = [];
        $n = strlen($expression);

        for ($i = 0; $i < $n; $i++) {
            $ch = $expression[$i];

            if ($ch == '+' || $ch == '-' || $ch == '*') {
                $left = $this->diffWaysToCompute(
                    substr($expression, 0, $i)
                );

                $right = $this->diffWaysToCompute(
                    substr($expression, $i + 1)
                );

                foreach ($left as $a) {
                    foreach ($right as $b) {
                        if ($ch == '+') {
                            $result[] = $a + $b;
                        }
                        elseif ($ch == '-') {
                            $result[] = $a - $b;
                        }
                        else {
                            $result[] = $a * $b;
                        }
                    }
                }
            }
        }

        if (empty($result)) {
            $result[] = intval($expression);
        }

        $this->memo[$expression] = $result;

        return $result;
    }
}