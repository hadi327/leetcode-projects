class Solution {
    public function subsetsWithDup($nums) {
        sort($nums);

        $result = [];
        $subset = [];

        $this->backtrack($nums, 0, $subset, $result);

        return $result;
    }

    private function backtrack($nums, $start, &$subset, &$result) {
        $result[] = $subset;

        $n = count($nums);

        for ($i = $start; $i < $n; $i++) {
            if ($i > $start && $nums[$i] == $nums[$i - 1]) {
                continue;
            }

            $subset[] = $nums[$i];

            $this->backtrack(
                $nums,
                $i + 1,
                $subset,
                $result
            );

            array_pop($subset);
        }
    }
}