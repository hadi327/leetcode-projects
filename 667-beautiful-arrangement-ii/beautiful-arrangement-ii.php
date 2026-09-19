class Solution {

    function constructArray($n, $k) {
        $result = [];
        $left = 1;
        $right = $n;

        while ($left <= $right) {
            if ($k > 1) {
                if ($k % 2 == 1) {
                    $result[] = $left++;
                } else {
                    $result[] = $right--;
                }

                $k--;
            } else {
                $result[] = $left++;
            }
        }

        return $result;
    }
}