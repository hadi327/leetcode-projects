class Solution {
    private $m;
    private $n;
    private $grid;

    private function dfs($r, $c) {
        $sum = $this->grid[$r][$c];
        $this->grid[$r][$c] = 0;

        $dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]];

        foreach ($dirs as $dir) {
            $nr = $r + $dir[0];
            $nc = $c + $dir[1];

            if (
                $nr >= 0 && $nr < $this->m &&
                $nc >= 0 && $nc < $this->n &&
                $this->grid[$nr][$nc] > 0
            ) {
                $sum += $this->dfs($nr, $nc);
            }
        }

        return $sum;
    }

    public function countIslands($grid, $k) {
        $this->grid = $grid;
        $this->m = count($grid);
        $this->n = count($grid[0]);

        $count = 0;

        for ($i = 0; $i < $this->m; $i++) {
            for ($j = 0; $j < $this->n; $j++) {
                if ($this->grid[$i][$j] > 0) {
                    $sum = $this->dfs($i, $j);

                    if ($sum % $k == 0) {
                        $count++;
                    }
                }
            }
        }

        return $count;
    }
}