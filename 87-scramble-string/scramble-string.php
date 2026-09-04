class Solution {
    private $memo = [];

    public function isScramble($s1, $s2) {
        if (strlen($s1) != strlen($s2)) {
            return false;
        }

        return $this->solve($s1, $s2);
    }

    private function solve($s1, $s2) {
        if ($s1 === $s2) {
            return true;
        }

        $key = $s1 . "#" . $s2;

        if (isset($this->memo[$key])) {
            return $this->memo[$key];
        }

        if (count_chars($s1, 1) != count_chars($s2, 1)) {
            return $this->memo[$key] = false;
        }

        $n = strlen($s1);

        for ($i = 1; $i < $n; $i++) {
            // No swap
            if (
                $this->solve(
                    substr($s1, 0, $i),
                    substr($s2, 0, $i)
                ) &&
                $this->solve(
                    substr($s1, $i),
                    substr($s2, $i)
                )
            ) {
                return $this->memo[$key] = true;
            }

            // Swap
            if (
                $this->solve(
                    substr($s1, 0, $i),
                    substr($s2, $n - $i)
                ) &&
                $this->solve(
                    substr($s1, $i),
                    substr($s2, 0, $n - $i)
                )
            ) {
                return $this->memo[$key] = true;
            }
        }

        return $this->memo[$key] = false;
    }
}