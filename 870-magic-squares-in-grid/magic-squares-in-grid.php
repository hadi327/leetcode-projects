class Solution {

    function numMagicSquaresInside($grid) {
        $rows = count($grid);
        $cols = count($grid[0]);
        $result = 0;

        for ($r = 0; $r <= $rows - 3; $r++) {
            for ($c = 0; $c <= $cols - 3; $c++) {
                if ($this->isMagic($grid, $r, $c)) {
                    $result++;
                }
            }
        }

        return $result;
    }

    private function isMagic($grid, $r, $c) {
        $seen = [];

        for ($i = 0; $i < 3; $i++) {
            for ($j = 0; $j < 3; $j++) {
                $value = $grid[$r + $i][$c + $j];

                if ($value < 1 || $value > 9 ||
                    isset($seen[$value])) {
                    return false;
                }

                $seen[$value] = true;
            }
        }

        $target =
            $grid[$r][$c] +
            $grid[$r][$c + 1] +
            $grid[$r][$c + 2];

        for ($i = 0; $i < 3; $i++) {
            $sum =
                $grid[$r + $i][$c] +
                $grid[$r + $i][$c + 1] +
                $grid[$r + $i][$c + 2];

            if ($sum != $target) {
                return false;
            }
        }

        for ($j = 0; $j < 3; $j++) {
            $sum =
                $grid[$r][$c + $j] +
                $grid[$r + 1][$c + $j] +
                $grid[$r + 2][$c + $j];

            if ($sum != $target) {
                return false;
            }
        }

        $diagonal1 =
            $grid[$r][$c] +
            $grid[$r + 1][$c + 1] +
            $grid[$r + 2][$c + 2];

        $diagonal2 =
            $grid[$r][$c + 2] +
            $grid[$r + 1][$c + 1] +
            $grid[$r + 2][$c];

        return $diagonal1 == $target &&
               $diagonal2 == $target;
    }
}