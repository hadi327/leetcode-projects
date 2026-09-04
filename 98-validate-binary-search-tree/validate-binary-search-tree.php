class Solution {
    public function isValidBST($root) {
        return $this->check($root, null, null);
    }

    private function check($node, $min, $max) {
        if ($node == null) {
            return true;
        }

        if ($min !== null && $node->val <= $min) {
            return false;
        }

        if ($max !== null && $node->val >= $max) {
            return false;
        }

        return $this->check($node->left, $min, $node->val) &&
               $this->check($node->right, $node->val, $max);
    }
}