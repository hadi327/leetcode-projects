class Solution {
    function sumCounts($nums) {
        $n = count($nums);
        $ans = 0;

        for ($i = 0; $i < $n; $i++) {
            $seen = [];
            $distinct = 0;

            for ($j = $i; $j < $n; $j++) {
                $x = $nums[$j];

                if (!isset($seen[$x])) {
                    $seen[$x] = true;
                    $distinct++;
                }

                $ans += $distinct * $distinct;
            }
        }

        return $ans;
    }
}