class Solution {

    /**
     * @param Integer[] $gain
     * @return Integer
     */
    function largestAltitude($gain) {
         $current = 0;
        $maxAltitude = 0;

        foreach ($gain as $g) {
            $current += $g;
            $maxAltitude = max($maxAltitude, $current);
        }

        return $maxAltitude;
    }
}