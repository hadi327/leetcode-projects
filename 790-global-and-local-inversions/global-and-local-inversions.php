class Solution {

    function isIdealPermutation($nums) {
        $max = -1;

        for ($i = 0; $i < count($nums) - 2; $i++) {
            $max = max($max, $nums[$i]);

            if ($max > $nums[$i + 2]) {
                return false;
            }
        }

        return true;
    }
}