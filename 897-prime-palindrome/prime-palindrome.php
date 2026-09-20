class Solution {

    function primePalindrome($n) {
        while (true) {
            if ($this->isPalindrome($n) &&
                $this->isPrime($n)) {
                return $n;
            }

            $n++;

            // No even-length palindrome > 11
            // can be prime.
            if ($n > 10000000 &&
                $n < 100000000) {
                $n = 100000000;
            }
        }
    }

    private function isPalindrome($n) {
        $s = (string)$n;

        return $s === strrev($s);
    }

    private function isPrime($n) {
        if ($n < 2) {
            return false;
        }

        if ($n == 2) {
            return true;
        }

        if ($n % 2 == 0) {
            return false;
        }

        for ($i = 3; $i * $i <= $n; $i += 2) {
            if ($n % $i == 0) {
                return false;
            }
        }

        return true;
    }
}