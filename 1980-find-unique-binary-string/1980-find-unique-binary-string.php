class Solution {

    /**
     * @param String[] $nums
     * @return String
     */
    function findDifferentBinaryString($nums) {
        $n = count($nums);
        $result = '';

        for ($i = 0; $i < $n; $i++) {
            // Invert the i-th character of the i-th string
            $result .= ($nums[$i][$i] === '0') ? '1' : '0';
        }

        return $result;
    }
}