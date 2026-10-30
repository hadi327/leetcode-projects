class Solution {
    public function shortestPath($n, $edges, $labels, $k) {
        $adj = array_fill(0, $n, []);

        foreach ($edges as $edge) {
            [$u, $v, $w] = $edge;
            $adj[$u][] = [$v, $w];
        }

        $INF = PHP_INT_MAX;
        $dist = array_fill(0, $n, array_fill(0, $k + 1, $INF));

        $pq = new SplPriorityQueue();
        $pq->setExtractFlags(SplPriorityQueue::EXTR_DATA);

        $dist[0][1] = 0;

        $pq->insert([0, 1, 0], 0);

        while (!$pq->isEmpty()) {
            [$node, $cnt, $cost] = $pq->extract();

            if ($cost > $dist[$node][$cnt]) {
                continue;
            }

            if ($node == $n - 1) {
                return $cost;
            }

            foreach ($adj[$node] as [$next, $weight]) {
                if ($labels[$node] == $labels[$next]) {
                    $newCnt = $cnt + 1;
                } else {
                    $newCnt = 1;
                }

                if ($newCnt > $k) {
                    continue;
                }

                $newCost = $cost + $weight;

                if ($newCost < $dist[$next][$newCnt]) {
                    $dist[$next][$newCnt] = $newCost;

                    $pq->insert(
                        [$next, $newCnt, $newCost],
                        -$newCost
                    );
                }
            }
        }

        return -1;
    }
}