class Solution {
    function majorityElement($nums) {
        $candidate1 = 0;
        $candidate2 = 0;
        $count1 = 0;
        $count2 = 0;

        foreach ($nums as $num) {
            if ($num == $candidate1) {
                $count1++;
            }
            elseif ($num == $candidate2) {
                $count2++;
            }
            elseif ($count1 == 0) {
                $candidate1 = $num;
                $count1 = 1;
            }
            elseif ($count2 == 0) {
                $candidate2 = $num;
                $count2 = 1;
            }
            else {
                $count1--;
                $count2--;
            }
        }

        $count1 = 0;
        $count2 = 0;

        foreach ($nums as $num) {
            if ($num == $candidate1) $count1++;
            if ($num == $candidate2) $count2++;
        }

        $result = [];
        $n = count($nums);

        if ($count1 > intdiv($n, 3)) {
            $result[] = $candidate1;
        }

        if ($candidate2 != $candidate1 &&
            $count2 > intdiv($n, 3)) {
            $result[] = $candidate2;
        }

        return $result;
    }
}