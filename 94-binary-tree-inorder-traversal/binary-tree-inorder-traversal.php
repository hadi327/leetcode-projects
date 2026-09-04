class Solution {
    public function inorderTraversal($root) {
        $result = [];

        $this->inorder($root, $result);

        return $result;
    }

    private function inorder($root, &$result) {
        if ($root == null) {
            return;
        }

        $this->inorder($root->left, $result);
        $result[] = $root->val;
        $this->inorder($root->right, $result);
    }
}