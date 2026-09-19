class Solution {

    function escapeGhosts($ghosts, $target) {
        $myDistance =
            abs($target[0]) +
            abs($target[1]);

        foreach ($ghosts as $ghost) {
            $ghostDistance =
                abs($ghost[0] - $target[0]) +
                abs($ghost[1] - $target[1]);

            if ($ghostDistance <= $myDistance) {
                return false;
            }
        }

        return true;
    }
}