class Solution {
    public function deleteDuplicates($head) {
        $dummy = new ListNode(0);
        $dummy->next = $head;

        $prev = $dummy;
        $current = $head;

        while ($current != null) {
            if ($current->next != null &&
                $current->val == $current->next->val) {

                $value = $current->val;

                while ($current != null && $current->val == $value) {
                    $current = $current->next;
                }

                $prev->next = $current;
            } else {
                $prev = $current;
                $current = $current->next;
            }
        }

        return $dummy->next;
    }
}