class Solution {
    function countSubarrays($nums, $minK, $maxK) {
        $n = count($nums);
        $lastMin = -1;
        $lastMax = -1;
        $lastBad = -1;
        $ans = 0;

        for ($i = 0; $i < $n; $i++) {
            if ($nums[$i] < $minK || $nums[$i] > $maxK) {
                $lastBad = $i;
            }

            if ($nums[$i] == $minK) {
                $lastMin = $i;
            }

            if ($nums[$i] == $maxK) {
                $lastMax = $i;
            }

            $ans += max(
                0,
                min($lastMin, $lastMax) - $lastBad
            );
        }

        return $ans;
    }
}