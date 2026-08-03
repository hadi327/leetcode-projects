class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $k
     * @return Integer
     */
    function longestOnes($nums, $k) {
         $left = 0;

        for ($right = 0; $right < count($nums); $right++) {
            if ($nums[$right] == 0) {
                $k--;
            }

            if ($k < 0) {
                if ($nums[$left] == 0) {
                    $k++;
                }
                $left++;
            }
        }

        return count($nums) - $left; 
    }
}