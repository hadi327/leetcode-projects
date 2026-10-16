
class Solution {
    private $sum = [];
    private $sq = [];
    private $lazy = [];
    private $mod = 1000000007;

    private function apply($node, $l, $r, $delta) {
        $len = $r - $l + 1;
        $oldSum = $this->sum[$node];

        $this->sq[$node] = (
            $this->sq[$node]
            + 2 * $delta * $oldSum
            + $delta * $delta * $len
        ) % $this->mod;

        $this->sum[$node] = (
            $oldSum + $delta * $len
        ) % $this->mod;

        $this->lazy[$node] = (
            $this->lazy[$node] + $delta
        ) % $this->mod;
    }

    private function push($node, $l, $r) {
        if ($this->lazy[$node] == 0 || $l == $r) {
            return;
        }

        $mid = intdiv($l + $r, 2);
        $delta = $this->lazy[$node];

        $this->apply($node * 2, $l, $mid, $delta);
        $this->apply($node * 2 + 1, $mid + 1, $r, $delta);

        $this->lazy[$node] = 0;
    }

    private function update($node, $l, $r, $ql, $qr) {
        if ($ql <= $l && $r <= $qr) {
            $this->apply($node, $l, $r, 1);
            return;
        }

        $this->push($node, $l, $r);
        $mid = intdiv($l + $r, 2);

        if ($ql <= $mid) {
            $this->update(
                $node * 2, $l, $mid, $ql, $qr
            );
        }

        if ($qr > $mid) {
            $this->update(
                $node * 2 + 1, $mid + 1, $r, $ql, $qr
            );
        }

        $this->sum[$node] = (
            $this->sum[$node * 2]
            + $this->sum[$node * 2 + 1]
        ) % $this->mod;

        $this->sq[$node] = (
            $this->sq[$node * 2]
            + $this->sq[$node * 2 + 1]
        ) % $this->mod;
    }

    function sumCounts($nums) {
        $n = count($nums);

        $this->sum = array_fill(0, 4 * $n + 5, 0);
        $this->sq = array_fill(0, 4 * $n + 5, 0);
        $this->lazy = array_fill(0, 4 * $n + 5, 0);

        $lastSeen = [];
        $answer = 0;

        for ($i = 0; $i < $n; $i++) {
            $value = $nums[$i];

            $last = isset($lastSeen[$value])
                ? $lastSeen[$value]
                : -1;

            // Increase distinct counts for valid subarrays.
            $this->update(
                1, 0, $n - 1, $last + 1, $i
            );

            $lastSeen[$value] = $i;

            // Add squared distinct counts of subarrays
            // ending at the current index.
            $answer = (
                $answer + $this->sq[1]
            ) % $this->mod;
        }

        return $answer;
    }
}
