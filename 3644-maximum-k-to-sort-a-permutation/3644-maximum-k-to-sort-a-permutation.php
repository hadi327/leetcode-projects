class Solution {
    public function sortPermutation($nums) {
        $ans = -1;

        foreach ($nums as $i => $x) {
            if ($i != $x) {
                $ans &= ($i & $x);
            }
        }

        return max($ans, 0);
    }
}