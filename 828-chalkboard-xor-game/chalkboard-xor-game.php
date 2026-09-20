class Solution {

    function xorGame($nums) {
        $xor = 0;

        foreach ($nums as $num) {
            $xor ^= $num;
        }

        return $xor == 0 || count($nums) % 2 == 0;
    }
}