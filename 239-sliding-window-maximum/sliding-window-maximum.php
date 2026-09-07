class Solution {
    function maxSlidingWindow($nums, $k) {
        $deque = [];
        $result = [];
        $n = count($nums);

        for ($i = 0; $i < $n; $i++) {

            // Remove elements outside the window
            while (!empty($deque) &&
                   $deque[0] <= $i - $k) {

                array_shift($deque);
            }

            // Remove smaller elements
            while (!empty($deque) &&
                   $nums[$deque[count($deque) - 1]] <= $nums[$i]) {

                array_pop($deque);
            }

            $deque[] = $i;

            if ($i >= $k - 1) {
                $result[] = $nums[$deque[0]];
            }
        }

        return $result;
    }
}