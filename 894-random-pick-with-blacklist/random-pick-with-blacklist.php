class Solution {

    private $bound;
    private $map = [];

    function __construct($n, $blacklist) {
        $this->bound = $n - count($blacklist);

        $black = [];
        foreach ($blacklist as $b) {
            $black[$b] = true;
        }

        $last = $n - 1;

        foreach ($blacklist as $b) {
            if ($b >= $this->bound) {
                continue;
            }

            while (isset($black[$last])) {
                $last--;
            }

            $this->map[$b] = $last;
            $last--;
        }
    }

    function pick() {
        $x = random_int(0, $this->bound - 1);

        return $this->map[$x] ?? $x;
    }
}