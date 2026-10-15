class Solution {
    private $tree;
    private $size;

    function lengthOfLIS($nums, $k) {
        $maxVal = max($nums);
        $this->size = $maxVal + 1;
        $this->tree = array_fill(0, 4 * $this->size, 0);

        $ans = 0;

        foreach ($nums as $num) {
            $left = max(0, $num - $k);
            $right = $num - 1;

            $best = 0;

            if ($left <= $right) {
                $best = $this->query(
                    1, 0, $this->size - 1, $left, $right
                );
            }

            $dp = $best + 1;

            $this->update(
                1, 0, $this->size - 1, $num, $dp
            );

            $ans = max($ans, $dp);
        }

        return $ans;
    }

    private function update($node, $start, $end, $idx, $val) {
        if ($start == $end) {
            $this->tree[$node] = max($this->tree[$node], $val);
            return;
        }

        $mid = intdiv($start + $end, 2);

        if ($idx <= $mid) {
            $this->update(
                $node * 2, $start, $mid, $idx, $val
            );
        } else {
            $this->update(
                $node * 2 + 1, $mid + 1, $end, $idx, $val
            );
        }

        $this->tree[$node] = max(
            $this->tree[$node * 2],
            $this->tree[$node * 2 + 1]
        );
    }

    private function query($node, $start, $end, $left, $right) {
        if ($right < $start || $end < $left) {
            return 0;
        }

        if ($left <= $start && $end <= $right) {
            return $this->tree[$node];
        }

        $mid = intdiv($start + $end, 2);

        return max(
            $this->query(
                $node * 2, $start, $mid, $left, $right
            ),
            $this->query(
                $node * 2 + 1, $mid + 1, $end, $left, $right
            )
        );
    }
}