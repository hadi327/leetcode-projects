class Solution {
    function isPalindrome($head) {
        $values = [];

        while ($head !== null) {
            $values[] = $head->val;
            $head = $head->next;
        }

        $left = 0;
        $right = count($values) - 1;

        while ($left < $right) {
            if ($values[$left] != $values[$right]) {
                return false;
            }

            $left++;
            $right--;
        }

        return true;
    }
}