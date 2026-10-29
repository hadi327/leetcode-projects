class Solution {
    private $adj;
    private $parent;
    private $depth;
    private $size;
    private $heavy;
    private $head;
    private $pos;
    private $seg;
    private $timer;

    public function palindromePath($n, $edges, $s, $queries) {
        $this->adj = array_fill(0, $n, []);

        foreach ($edges as $e) {
            $u = $e[0];
            $v = $e[1];
            $this->adj[$u][] = $v;
            $this->adj[$v][] = $u;
        }

        $this->parent = array_fill(0, $n, -1);
        $this->depth = array_fill(0, $n, 0);
        $this->size = array_fill(0, $n, 1);
        $this->heavy = array_fill(0, $n, -1);
        $this->head = array_fill(0, $n, 0);
        $this->pos = array_fill(0, $n, 0);

        $order = [];
        $stack = [0];
        $this->parent[0] = 0;

        while (!empty($stack)) {
            $u = array_pop($stack);
            $order[] = $u;

            foreach ($this->adj[$u] as $v) {
                if ($v == $this->parent[$u]) {
                    continue;
                }

                $this->parent[$v] = $u;
                $this->depth[$v] = $this->depth[$u] + 1;
                $stack[] = $v;
            }
        }

        for ($i = count($order) - 1; $i >= 0; $i--) {
            $u = $order[$i];
            $bestSize = 0;

            foreach ($this->adj[$u] as $v) {
                if ($this->parent[$v] != $u) {
                    continue;
                }

                $this->size[$u] += $this->size[$v];

                if ($this->size[$v] > $bestSize) {
                    $bestSize = $this->size[$v];
                    $this->heavy[$u] = $v;
                }
            }
        }

        $this->timer = 0;
        $todo = [[0, 0]];

        while (!empty($todo)) {
            [$u, $h] = array_pop($todo);

            for ($x = $u; $x != -1; $x = $this->heavy[$x]) {
                $this->head[$x] = $h;
                $this->pos[$x] = $this->timer++;

                foreach ($this->adj[$x] as $v) {
                    if (
                        $this->parent[$v] == $x &&
                        $v != $this->heavy[$x]
                    ) {
                        $todo[] = [$v, $v];
                    }
                }
            }
        }

        $base = array_fill(0, $n, 0);

        for ($u = 0; $u < $n; $u++) {
            $base[$this->pos[$u]] = 1 << (ord($s[$u]) - ord('a'));
        }

        $this->seg = array_fill(0, 4 * $n, 0);
        $this->build(1, 0, $n - 1, $base);

        $answer = [];

        foreach ($queries as $q) {
            $parts = explode(' ', $q);

            if ($parts[0] === 'update') {
                $u = (int)$parts[1];
                $c = $parts[2];

                $s[$u] = $c;

                $mask = 1 << (ord($c) - ord('a'));

                $this->update(
                    1, 0, $n - 1, $this->pos[$u], $mask
                );
            } else {
                $u = (int)$parts[1];
                $v = (int)$parts[2];

                $mask = $this->pathQuery($u, $v);

                $answer[] = (($mask & ($mask - 1)) == 0);
            }
        }

        return $answer;
    }

    private function build($node, $l, $r, &$base) {
        if ($l == $r) {
            $this->seg[$node] = $base[$l];
            return;
        }

        $mid = intdiv($l + $r, 2);

        $this->build($node * 2, $l, $mid, $base);
        $this->build($node * 2 + 1, $mid + 1, $r, $base);

        $this->seg[$node] =
            $this->seg[$node * 2] ^
            $this->seg[$node * 2 + 1];
    }

    private function update($node, $l, $r, $idx, $value) {
        if ($l == $r) {
            $this->seg[$node] = $value;
            return;
        }

        $mid = intdiv($l + $r, 2);

        if ($idx <= $mid) {
            $this->update($node * 2, $l, $mid, $idx, $value);
        } else {
            $this->update(
                $node * 2 + 1, $mid + 1, $r, $idx, $value
            );
        }

        $this->seg[$node] =
            $this->seg[$node * 2] ^
            $this->seg[$node * 2 + 1];
    }

    private function rangeQuery($node, $l, $r, $ql, $qr) {
        if ($ql > $r || $qr < $l) {
            return 0;
        }

        if ($ql <= $l && $r <= $qr) {
            return $this->seg[$node];
        }

        $mid = intdiv($l + $r, 2);

        return $this->rangeQuery(
            $node * 2, $l, $mid, $ql, $qr
        ) ^ $this->rangeQuery(
            $node * 2 + 1, $mid + 1, $r, $ql, $qr
        );
    }

    private function pathQuery($u, $v) {
        $mask = 0;
        $n = count($this->parent);

        while ($this->head[$u] != $this->head[$v]) {
            if (
                $this->depth[$this->head[$u]] <
                $this->depth[$this->head[$v]]
            ) {
                [$u, $v] = [$v, $u];
            }

            $mask ^= $this->rangeQuery(
                1, 0, $n - 1,
                $this->pos[$this->head[$u]],
                $this->pos[$u]
            );

            $u = $this->parent[$this->head[$u]];
        }

        if ($this->depth[$u] > $this->depth[$v]) {
            [$u, $v] = [$v, $u];
        }

        $mask ^= $this->rangeQuery(
            1, 0, $n - 1,
            $this->pos[$u],
            $this->pos[$v]
        );

        return $mask;
    }
}