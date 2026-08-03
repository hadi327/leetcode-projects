class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function longestSubarray($nums) {
         $left = 0;
        $zeros = 0;
        $maxLen = 0;

        for ($right = 0; $right < count($nums); $right++) {
            if ($nums[$right] == 0) {
                $zeros++;
            }

            while ($zeros > 1) {
                if ($nums[$left] == 0) {
                    $zeros--;
                }
                $left++;
            }

            $maxLen = max($maxLen, $right - $left);
        }

        return $maxLen;
    }
}