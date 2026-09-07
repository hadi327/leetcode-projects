class Solution {
    function lowestCommonAncestor($root, $p, $q) {
        while ($root !== null) {
            if ($p->val < $root->val &&
                $q->val < $root->val) {

                $root = $root->left;
            }
            elseif ($p->val > $root->val &&
                    $q->val > $root->val) {

                $root = $root->right;
            }
            else {
                return $root;
            }
        }

        return null;
    }
}