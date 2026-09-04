class Solution {
    public function largestRectangleArea($heights) {
        $stack = [];
        $maxArea = 0;
        $n = count($heights);

        for ($i = 0; $i <= $n; $i++) {
            $height = ($i == $n) ? 0 : $heights[$i];

            while (!empty($stack) &&
                   $height < $heights[end($stack)]) {

                $top = array_pop($stack);
                $h = $heights[$top];

                $width = empty($stack)
                    ? $i
                    : $i - end($stack) - 1;

                $maxArea = max($maxArea, $h * $width);
            }

            $stack[] = $i;
        }

        return $maxArea;
    }
}