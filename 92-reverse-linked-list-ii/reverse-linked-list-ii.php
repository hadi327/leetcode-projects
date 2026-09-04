class Solution {
    public function reverseBetween($head, $left, $right) {
        if ($head == null || $left == $right) {
            return $head;
        }

        $dummy = new ListNode(0);
        $dummy->next = $head;

        $prev = $dummy;

        for ($i = 1; $i < $left; $i++) {
            $prev = $prev->next;
        }

        $current = $prev->next;

        for ($i = 0; $i < $right - $left; $i++) {
            $next = $current->next;
            $current->next = $next->next;
            $next->next = $prev->next;
            $prev->next = $next;
        }

        return $dummy->next;
    }
}