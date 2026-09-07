class Solution {
    function countNodes($root) {
        if ($root === null) {
            return 0;
        }

        $left = $root;
        $right = $root;

        $leftHeight = 0;
        $rightHeight = 0;

        while ($left !== null) {
            $leftHeight++;
            $left = $left->left;
        }

        while ($right !== null) {
            $rightHeight++;
            $right = $right->right;
        }

        if ($leftHeight == $rightHeight) {
            return (1 << $leftHeight) - 1;
        }

        return 1 +
            $this->countNodes($root->left) +
            $this->countNodes($root->right);
    }
}