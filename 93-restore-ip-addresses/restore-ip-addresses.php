class Solution {
    public function restoreIpAddresses($s) {
        $result = [];
        $this->backtrack($s, 0, [], $result);
        return $result;
    }

    private function backtrack($s, $index, $parts, &$result) {
        if (count($parts) == 4) {
            if ($index == strlen($s)) {
                $result[] = implode('.', $parts);
            }
            return;
        }

        for ($len = 1; $len <= 3; $len++) {
            if ($index + $len > strlen($s)) {
                break;
            }

            $part = substr($s, $index, $len);

            if (($part[0] == '0' && $len > 1) || intval($part) > 255) {
                continue;
            }

            $parts[] = $part;
            $this->backtrack($s, $index + $len, $parts, $result);
            array_pop($parts);
        }
    }
}