
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation.
 * interface MountainArray {
 *     public function get($index);
 *     public function length();
 * }
 */

class Solution {
    public function findInMountainArray($target, $mountainArr) {
        $n = $mountainArr->length();

        // 1. Find the peak index
        $left = 0;
        $right = $n - 1;

        while ($left < $right) {
            $mid = intdiv($left + $right, 2);

            if ($mountainArr->get($mid) <
                $mountainArr->get($mid + 1)) {
                $left = $mid + 1;
            } else {
                $right = $mid;
            }
        }

        $peak = $left;

        // 2. Search the increasing part
        $left = 0;
        $right = $peak;

        while ($left <= $right) {
            $mid = intdiv($left + $right, 2);
            $value = $mountainArr->get($mid);

            if ($value == $target) {
                return $mid;
            } elseif ($value < $target) {
                $left = $mid + 1;
            } else {
                $right = $mid - 1;
            }
        }

        // 3. Search the decreasing part
        $left = $peak + 1;
        $right = $n - 1;

        while ($left <= $right) {
            $mid = intdiv($left + $right, 2);
            $value = $mountainArr->get($mid);

            if ($value == $target) {
                return $mid;
            } elseif ($value > $target) {
                $left = $mid + 1;
            } else {
                $right = $mid - 1;
            }
        }

        return -1;
    }
}
