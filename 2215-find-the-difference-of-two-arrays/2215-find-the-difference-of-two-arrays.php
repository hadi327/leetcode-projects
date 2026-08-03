class Solution {

    /**
     * @param Integer[] $nums1
     * @param Integer[] $nums2
     * @return Integer[][]
     */
    function findDifference($nums1, $nums2) {
         $set1 = [];
        $set2 = [];

        foreach ($nums1 as $num) {
            $set1[$num] = true;
        }

        foreach ($nums2 as $num) {
            $set2[$num] = true;
        }

        $ans1 = [];
        foreach ($set1 as $num => $_) {
            if (!isset($set2[$num])) {
                $ans1[] = (int)$num;
            }
        }

        $ans2 = [];
        foreach ($set2 as $num => $_) {
            if (!isset($set1[$num])) {
                $ans2[] = (int)$num;
            }
        }

        return [$ans1, $ans2]; 
    }
}