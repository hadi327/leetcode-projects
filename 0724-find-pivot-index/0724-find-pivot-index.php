class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function pivotIndex($nums) {
         $totalSum = array_sum($nums);
        $leftSum = 0;

        for ($i = 0; $i < count($nums); $i++) {
            $rightSum = $totalSum - $leftSum - $nums[$i];

            if ($leftSum == $rightSum) {
                return $i;
            }

            $leftSum += $nums[$i];
        }

        return -1;
    }
}