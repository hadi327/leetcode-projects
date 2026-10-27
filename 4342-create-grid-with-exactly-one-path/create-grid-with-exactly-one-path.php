class Solution {
    public function createGrid($m, $n) {
        $grid = array_fill(0, $m, str_repeat('#', $n));

        $grid[0] = str_repeat('.', $n);

        for ($i = 0; $i < $m; $i++) {
            $grid[$i][$n - 1] = '.';
        }

        return $grid;
    }
}