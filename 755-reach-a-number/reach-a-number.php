class Solution {

    function reachNumber($target) {
        $target = abs($target);

        $sum = 0;
        $steps = 0;

        while ($sum < $target ||
               (($sum - $target) % 2 != 0)) {

            $steps++;
            $sum += $steps;
        }

        return $steps;
    }
}