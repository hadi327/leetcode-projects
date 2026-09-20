class Solution {

    function soupServings($n) {
        if ($n >= 4800) {
            return 1.0;
        }

        $n = intdiv($n + 24, 25);

        $memo = [];

        return $this->dfs($n, $n, $memo);
    }

    private function dfs($a, $b, &$memo) {
        if ($a <= 0 && $b <= 0) {
            return 0.5;
        }

        if ($a <= 0) {
            return 1.0;
        }

        if ($b <= 0) {
            return 0.0;
        }

        $key = $a . "," . $b;

        if (isset($memo[$key])) {
            return $memo[$key];
        }

        $memo[$key] = (
            $this->dfs($a - 4, $b, $memo) +
            $this->dfs($a - 3, $b - 1, $memo) +
            $this->dfs($a - 2, $b - 2, $memo) +
            $this->dfs($a - 1, $b - 3, $memo)
        ) / 4.0;

        return $memo[$key];
    }
}