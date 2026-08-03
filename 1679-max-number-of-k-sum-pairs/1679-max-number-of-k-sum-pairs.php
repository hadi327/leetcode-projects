class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $k
     * @return Integer
     */
    function maxOperations($nums, $k) {
        $freq = [];
        $count = 0;

        foreach ($nums as $num) {
            $target = $k - $num;

            if (isset($freq[$target]) && $freq[$target] > 0) {
                $freq[$target]--;
                $count++;
            } else {
                if (!isset($freq[$num])) {
                    $freq[$num] = 0;
                }
                $freq[$num]++;
            }
        }

        return $count;
    }
}