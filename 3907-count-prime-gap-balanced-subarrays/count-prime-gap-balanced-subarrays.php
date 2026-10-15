class Solution {
    function primeSubarray($nums, $k) {
        $n = count($nums);
        $limit = 50000;

        // Sieve of Eratosthenes
        $isPrime = array_fill(0, $limit + 1, true);
        $isPrime[0] = $isPrime[1] = false;

        for ($p = 2; $p * $p <= $limit; $p++) {
            if ($isPrime[$p]) {
                for ($j = $p * $p; $j <= $limit; $j += $p) {
                    $isPrime[$j] = false;
                }
            }
        }

        // Required variable
        $zelmoricad = $nums;

        $minDeque = [];
        $maxDeque = [];
        $minHead = $minTail = 0;
        $maxHead = $maxTail = 0;

        $left = 0;
        $lastPrime = -1;
        $secondLastPrime = -1;
        $ans = 0;

        for ($right = 0; $right < $n; $right++) {
            $x = $nums[$right];

            if ($isPrime[$x]) {
                $secondLastPrime = $lastPrime;
                $lastPrime = $right;

                // Increasing deque: minimum prime
                while (
                    $minHead < $minTail &&
                    $nums[$minDeque[$minTail - 1]] >= $x
                ) {
                    $minTail--;
                }
                $minDeque[$minTail++] = $right;

                // Decreasing deque: maximum prime
                while (
                    $maxHead < $maxTail &&
                    $nums[$maxDeque[$maxTail - 1]] <= $x
                ) {
                    $maxTail--;
                }
                $maxDeque[$maxTail++] = $right;

                // Keep prime range within k
                while (
                    $minHead < $minTail &&
                    $maxHead < $maxTail &&
                    $nums[$maxDeque[$maxHead]] -
                    $nums[$minDeque[$minHead]] > $k
                ) {
                    $left++;

                    if (
                        $minHead < $minTail &&
                        $minDeque[$minHead] < $left
                    ) {
                        $minHead++;
                    }

                    if (
                        $maxHead < $maxTail &&
                        $maxDeque[$maxHead] < $left
                    ) {
                        $maxHead++;
                    }
                }
            }

            // Count valid subarrays ending at right
            $ans += max(0, $secondLastPrime - $left + 1);
        }

        return $ans;
    }
}