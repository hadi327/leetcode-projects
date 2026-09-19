class Solution {

    function kthGrammar($n, $k) {
        $result = 0;

        while ($n > 1) {
            if ($k % 2 == 0) {
                $result ^= 1;
            }

            $k = intdiv($k + 1, 2);
            $n--;
        }

        return $result;
    }
}